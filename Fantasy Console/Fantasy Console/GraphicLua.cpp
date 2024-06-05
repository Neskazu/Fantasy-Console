#include "GraphicLua.h"

//const values
const int gridSize = 32; // tilemap size 
const int tileSize = 16; // tile size x,y
const int tileSetSize = 16;//tiles in row collumn
//tiles
struct Tile {
    int tileId;
    int textureId;
};

//tiles
Tile* tileMap;
Texture2D tileSet;
//textures
Texture2D* textures;
int textureId = 0;

//extra init
Rectangle srcRect = { 0, 0, 0, 0 };
Rectangle dstRect = { 0, 0, 0, 0 };
Vector2 pos = { 0, 0 };

//memory pool
MemoryPool* memoryPool = MemoryPool::getInstance(40096);

int LuaDrawText(lua_State* L)
{
    const char* text = luaL_checkstring(L, 1);
    float x = luaL_checknumber(L, 2);
    float y = luaL_checknumber(L, 3);
    int fontSize = luaL_checkinteger(L, 4);
    int colorId = luaL_checkinteger(L, 5);
    DrawText(text, x, y, fontSize, Colors::baseColors[colorId]);
    return 0;
}
int LuaLoadTexture(lua_State* L)
{
   
    int offset = 30000;
    char* baseAddress = memoryPool->GetMemoryBlock();
    void* targetAddress = baseAddress + offset;


    std::string path = luaL_checkstring(L, 1); // Get args from lua
    Image image = LoadImage(("Resources/" + path).c_str());     // Loaded in CPU memory (RAM)
    Texture2D texture = LoadTextureFromImage(image);          // Image converted to texture, GPU memory (VRAM)


    textures = memoryPool->Allocate<Texture2D>(targetAddress);
    textures[textureId] = texture;
    textureId++;
    UnloadImage(image);
    return 0;

}


int LuaDrawTexture(lua_State* L)
{
    int num_args = lua_gettop(L);//get args count 
    if (num_args == 6)
    {
        int id = luaL_checkinteger(L, 1);// Get args from lua
        float x = luaL_checknumber(L, 2);
        float y = luaL_checknumber(L, 3);
        int srcWidth = luaL_checkinteger(L, 4);
        int srcHeight = luaL_checkinteger(L, 5);
        int rotation = luaL_checkinteger(L, 6);
        //fill rects and vectors
        dstRect.x = x;
        dstRect.y = y;
        dstRect.width = srcWidth;
        dstRect.height = srcHeight;
        srcRect.height = srcHeight;
        srcRect.width = srcWidth;
        pos.x = 0;
        pos.y = 0;
        DrawTexturePro
        (
            textures[id],
            srcRect,
            dstRect,
            pos,
            rotation,
            WHITE
        );
    }
    if (num_args==11)
    {
        int id = luaL_checkinteger(L, 1);// Get args from lua
        float srcX = luaL_checknumber(L, 2);
        float srcY = luaL_checknumber(L, 3);
        float dstX = luaL_checknumber(L, 4);
        float dstY = luaL_checknumber(L, 5);
        int srcWidth = luaL_checkinteger(L, 6);
        int srcHeight = luaL_checkinteger(L, 7);
        int dstWidth = luaL_checkinteger(L, 8);
        int dstHeight = luaL_checkinteger(L, 9);
        int rotation = luaL_checkinteger(L, 10);
        int colorId = luaL_checkinteger(L, 11);
        //fill rects and vectors
        srcRect.x = srcX;
        srcRect.y = srcY;
        srcRect.height = srcHeight;
        srcRect.width = srcWidth;
        dstRect.x = dstX;
        dstRect.y = dstY;
        dstRect.width = dstWidth;
        dstRect.height = dstHeight;
        pos.x = 0;
        pos.y = 0;
        DrawTexturePro
        (
            textures[id],
            srcRect,
            dstRect,
            pos,
            rotation,
            Colors::baseColors[colorId]
        );
    }

    return 0;
}


int LuaInitializeTileMap(lua_State* L)
{
    tileMap = memoryPool->Allocate<Tile>(memoryPool->GetMemoryBlock(), gridSize * gridSize);
    //clear tilemap
    for (int i = 0; i < gridSize * gridSize; i++)
    {
        tileMap[i].tileId = -1;
        tileMap[i].textureId = -1;

    }
    return 0;
}
int LuaSetTile(lua_State* L)
{
    int x = luaL_checkinteger(L, 1); // Get args from lua
    int y = luaL_checkinteger(L, 2);
    int tileindex= luaL_checkinteger(L, 3);
    int textureId = luaL_optinteger(L, 4, 0);
    tileMap[y*gridSize+x].tileId = tileindex;
    tileMap[y * gridSize + x].textureId = textureId;
    return 0;
}

//Render tilemap every Frame
int  LuaRenderTileMap(lua_State* L)
{
    for (int y = 0; y < gridSize; y++)
    {
        for (int x = 0; x < gridSize; x++)
        {
            
            int tileIndex = tileMap[y*gridSize+x].tileId;
            Texture2D texture = textures[tileMap[y * gridSize + x].textureId];

            if (tileIndex >= 0)
            {
                srcRect.width = tileSize;
                srcRect.height = tileSize;
                srcRect.x = (tileIndex*tileSize)% texture.width;
                srcRect.y = tileIndex*tileSize/texture.width*tileSize;
                pos.x = x * tileSize;
                pos.y = y * tileSize;
                DrawTextureRec(texture, srcRect, pos, WHITE);
            }
        }
    }
    return 0;
}
//Geometric Primitives
int LuaDrawLine(lua_State* L)
{
    float startX = luaL_checknumber(L, 1);
    float startY = luaL_checknumber(L, 2);
    float endX = luaL_checknumber(L, 3);
    float endY = luaL_checknumber(L, 4);
    int colorId = luaL_checkinteger(L, 5);
    DrawLine(startX, startY, endX, endY, Colors::baseColors[colorId]);
    return 0;
}
int LuaDrawCircle(lua_State* L)
{
    float centerX = luaL_checknumber(L, 1);
    float centerY = luaL_checknumber(L, 2);
    float radius = luaL_checknumber(L, 3);
    int colorId = luaL_checkinteger(L, 4);
    DrawCircle(centerX, centerY, radius, Colors::baseColors[colorId]);
    return 0;
}
int LuaDrawTriangle(lua_State* L)
{
    Vector2* v1 = (Vector2*)luaL_checkudata(L, 1, "Vector2MetaTable");
    Vector2* v2 = (Vector2*)luaL_checkudata(L, 2, "Vector2MetaTable");
    Vector2* v3 = (Vector2*)luaL_checkudata(L, 3, "Vector2MetaTable");
    int colorId = luaL_checkinteger(L, 4);
    DrawTriangle(*v1,*v2,*v3,Colors::baseColors[colorId]);
    return 0;
}
int LuaDrawRectangle(lua_State* L)
{
    float x = luaL_checknumber(L, 1);
    float y = luaL_checknumber(L, 2);
    int width = luaL_checkinteger(L, 3);
    int height = luaL_checkinteger(L, 4);
    int colorId = luaL_checkinteger(L, 5);
    DrawRectangle(x, y, width, height, Colors::baseColors[colorId]);
    return 0;
}