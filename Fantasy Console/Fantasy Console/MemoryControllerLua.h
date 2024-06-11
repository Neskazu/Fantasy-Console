#pragma once
#include "lua.hpp"
#include "MemoryPool.h"
int LuaGetMemoryPoolInstance(lua_State* L);
int LuaGetMemoryBlock(lua_State* L);
int LuaSetMemoryBlock(lua_State* L);

