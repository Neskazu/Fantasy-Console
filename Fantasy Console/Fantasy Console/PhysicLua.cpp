#include "PhysicLua.h"
//Check collision between 2 recs
int LuaCheckCollisionRecs(lua_State* L) 
{
    Rectangle rec1;
    rec1.x = luaL_checknumber(L, 1);
    rec1.y = luaL_checknumber(L, 2);
    rec1.width = luaL_checknumber(L, 3);
    rec1.height = luaL_checknumber(L, 4);

    Rectangle rec2;
    rec2.x = luaL_checknumber(L, 5);
    rec2.y = luaL_checknumber(L, 6);
    rec2.width = luaL_checknumber(L, 7);
    rec2.height = luaL_checknumber(L, 8);

    bool result = CheckCollisionRecs(rec1, rec2);
    lua_pushboolean(L, result);
    return 1;
}
//Check collision between 2 circles
int LuaCheckCollisionCircles(lua_State* L) 
{
    float x1 = luaL_checknumber(L, 1);
    float y1 = luaL_checknumber(L, 2);
    float radius1 = luaL_checknumber(L, 3);
    float x2 = luaL_checknumber(L, 4);
    float y2 = luaL_checknumber(L, 5);
    float radius2 = luaL_checknumber(L, 6);

    bool result = CheckCollisionCircles({ x1, y1 }, radius1, { x2, y2 }, radius2);
    lua_pushboolean(L, result);
    return 1;
}
//check is point in rec
int LuaCheckCollisionPointRec(lua_State* L) 
{
    float px = luaL_checknumber(L, 1);
    float py = luaL_checknumber(L, 2);

    Rectangle rec;
    rec.x = luaL_checknumber(L, 3);
    rec.y = luaL_checknumber(L, 4);
    rec.width = luaL_checknumber(L, 5);
    rec.height = luaL_checknumber(L, 6);

    bool result = CheckCollisionPointRec({ px, py }, rec);
    lua_pushboolean(L, result);
    return 1;
}