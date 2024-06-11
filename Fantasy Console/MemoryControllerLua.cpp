#include "MemoryControllerLua.h"

int LuaGetMemoryPoolInstance(lua_State* L)
{
    
    lua_pushlightuserdata(L, MemoryPool::GetInstance(1));
    return 1;
}

int LuaGetMemoryBlock(lua_State* L)
{
    MemoryPool* pool = MemoryPool::GetInstance(1);
    lua_pushlightuserdata(L, pool->GetMemoryBlock());
    return 1;
}

int LuaSetMemoryBlock(lua_State* L)
{
    MemoryPool* pool = MemoryPool::GetInstance(1);
    char* baseAddress = pool->GetMemoryBlock();
    const char* value = luaL_checkstring(L, 1);
    int startIndex = luaL_checkinteger(L, 2);
    int endIndex = luaL_optinteger(L, 3, startIndex + 1);
    for (int i = startIndex; i < endIndex; i++)
    {
        baseAddress[i] = value[0];
    }
    return 0;
}
