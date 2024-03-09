#include "raylib.h"
#include "lua.hpp"
#include "Colors.h"

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