#pragma once
#include "lua.hpp"
#include "raylib.h"
#include "Controls.h"

int LuaGetVirtualJoystick(lua_State* L);
int LuaGetVirtualMouse(lua_State* L);
int LuaGetDeltaTime(lua_State* L);
