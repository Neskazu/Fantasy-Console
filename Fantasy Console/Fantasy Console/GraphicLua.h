#pragma once
#include "raylib.h"
#include "lua.hpp"
#include "Colors.h"
#include <string>
#include <unordered_map>
#include "MemoryPool.h"
#include <iostream>
int LuaInitializeTileMap(lua_State* L);
int LuaSetTile(lua_State* L);
int LuaRenderTileMap(lua_State* L);
int LuaLoadTexture(lua_State* L);
int LuaDrawTexture(lua_State* L);
int LuaDrawText(lua_State* L);
int LuaDrawTriangle(lua_State* L);
int LuaDrawCircle(lua_State* L);
int LuaDrawRectangle(lua_State* L);
int LuaDrawText(lua_State* L);
