#include "raylib.h"
#include "lua.hpp"
#include "Colors.h"
#include <string>
#include <unordered_map>

//const values
const int gridSize = 32; // tilemap size 
const int tileSize = 16; // tile size x,y

std::unordered_map<std::string, Texture2D> textureCache;

int LuaDrawCircle(lua_State* L) {
    int x = luaL_checkinteger(L, 1); // Get args from lua
    int y = luaL_checkinteger(L, 2);
    int radius = luaL_checkinteger(L, 3);
    int colorIndex = luaL_checkinteger(L, 4);

    // Check isvalid
    if (colorIndex >= 0 && colorIndex < Colors::numBaseColors) {
        DrawCircle(x, y, radius, Colors::baseColors[colorIndex]); // Draw call
    }

    return 0;
}
int LuaDrawPixel(lua_State* L)
{
    int x = luaL_checkinteger(L, 1); // Get args from lua
    int y = luaL_checkinteger(L, 2);
    int colorIndex = luaL_checkinteger(L, 3);
    if (colorIndex >= 0 && colorIndex < Colors::numBaseColors) {
        DrawPixel(x, y,Colors::baseColors[colorIndex]); // Draw call
    }
    return 0;

}
int LuaPlaceTile(lua_State* L)
{
    std::string path = luaL_checkstring(L, 1); // Get args from lua
    int x = luaL_checkinteger(L, 2);
    int y = luaL_checkinteger(L, 3);
    // check texture in cache
    auto it = textureCache.find(path);
    if (it == textureCache.end())
    {
        //load
        Image image = LoadImage(("Resources/" + path).c_str());     // Loaded in CPU memory (RAM)
        Texture2D texture = LoadTextureFromImage(image);          // Image converted to texture, GPU memory (VRAM)
        UnloadImage(image);
        //add to cache
        textureCache[path] = texture;
        //draw
        DrawTexture(texture, tileSize * x, tileSize * y, WHITE);
    }
    else
    {
        //draw from cache
        DrawTexture(it->second, tileSize * x, tileSize * y, WHITE);
    }
    return 0;
}
int LuaPlaceSprite(lua_State* L)
{
    std::string path = luaL_checkstring(L, 1); // Get args from lua
    int x = luaL_checkinteger(L, 2);
    int y = luaL_checkinteger(L, 3);
    int width = luaL_checkinteger(L, 4);
    int height = luaL_checkinteger(L, 5);
    //extra init
    Rectangle srcRect = { 0, 0, width, height };
    Rectangle destRect = { x, y, width, height };
    Vector2 origin = { 0, 0 };
    
    auto it = textureCache.find(path);
    if (it == textureCache.end())
    {
        //load
        Image image = LoadImage(("Resources/" + path).c_str());     // Loaded in CPU memory (RAM)
        Texture2D texture = LoadTextureFromImage(image);          // Image converted to texture, GPU memory (VRAM)
        UnloadImage(image);
        //add to cache
        textureCache[path] = texture;
        //draw
        DrawTexturePro(texture, srcRect, destRect, origin, 0, WHITE);
    }
    else
    {
        //draw
        DrawTexturePro(it->second, srcRect, destRect, origin, 0, WHITE);
    }


    return 0;
}