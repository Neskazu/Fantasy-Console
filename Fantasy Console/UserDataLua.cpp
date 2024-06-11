#include "UserDataLua.h"

//Vector representation in lua (qol component)
int LuaCreateVector2(lua_State* L) {
    float x = luaL_checknumber(L, 1);
    float y = luaL_checknumber(L, 2);

    Vector2* v = (Vector2*)lua_newuserdata(L, sizeof(Vector2));
    v->x = x;
    v->y = y;
    luaL_getmetatable(L, "Vector2MetaTable");
    lua_setmetatable(L, -2);

    return 1;
}
int LuaGetVector2(lua_State* L) {
    Vector2* v = (Vector2*)luaL_checkudata(L, 1, "Vector2MetaTable");
    lua_pushnumber(L, v->x);
    lua_pushnumber(L, v->y);

    return 2;
}
int LuaSetVector2(lua_State* L) {
    Vector2* v = (Vector2*)luaL_checkudata(L, 1, "Vector2MetaTable");
    v->x = luaL_checknumber(L, 2);
    v->y = luaL_checknumber(L, 3);

    return 0;
}