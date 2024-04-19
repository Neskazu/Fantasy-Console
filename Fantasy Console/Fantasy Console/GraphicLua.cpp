#include "raylib.h"
#include "lua.hpp"
#include "Colors.h"
#include <string>
#include <unordered_map>

//const values
const int gridSize = 32; // tilemap size 
const int tileSize = 16; // tile size x,y
const int tileSetSize = 16;//tiles in row collumn

//tiles
int tileMap[gridSize][gridSize];//tiles map 
Texture2D tileSet;

//extra init
Rectangle srcRect = { 0, 0, tileSize, tileSize };
Vector2 pos = { 0, 0 };


int LuaLoadTileSet(lua_State* L)
{
    std::string path = luaL_checkstring(L, 1); // Get args from lua
    Image image = LoadImage(("Resources/" + path).c_str());     // Loaded in CPU memory (RAM)
    Texture2D texture = LoadTextureFromImage(image);          // Image converted to texture, GPU memory (VRAM)
    UnloadImage(image);
    tileSet = texture;
    //clear tilemap
    for (int y = 0; y < gridSize; y++)
    {
        for (int x = 0; x < gridSize; x++)
        {
            tileMap[x][y] = -1;
        }
    }
    return 0;
}
int LuaSetTile(lua_State* L)
{
    int x = luaL_checkinteger(L, 1); // Get args from lua
    int y = luaL_checkinteger(L, 2);
    int tileindex= luaL_checkinteger(L, 3);
    tileMap[x][y] = tileindex;
    return 0;
}
//Render tilemap every Frame
int  LuaRenderTileMap(lua_State* L)
{
    for (int y = 0; y < gridSize; y++)
    {
        for (int x = 0; x < gridSize; x++)
        {
            
            int tileIndex = tileMap[x][y];
            if (tileIndex >= 0)
            {
                srcRect.x = (tileIndex*tileSize)% tileSet.width;
                srcRect.y = tileIndex*tileSize/tileSet.width*tileSize;
                pos.x = x * tileSize;
                pos.y = y * tileSize;
                DrawTextureRec(tileSet, srcRect, pos, WHITE);
            }
        }
    }
    return 0;
}
