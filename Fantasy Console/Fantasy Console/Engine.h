#pragma once
#include<iostream>
#include "lua.hpp"
#pragma comment(lib,"lua54") // LUA version 5.4
using namespace std;
class Lua
{
private:
	lua_State* lua_state;
public:
	void Init()  // инициализируем и подключаем модули.
	{
		lua_state = luaL_newstate();
		static const luaL_Reg lualibs[] =
		{
			{ "base", luaopen_base },
			{ "io", luaopen_io },
			{ "os",luaopen_os },
			{ "math",luaopen_math },
			{ "table",luaopen_table },
			{ "string",luaopen_string },
			{ "package",luaopen_package },
			{ NULL, NULL }
		};
		for (const luaL_Reg* lib = lualibs; lib->func != NULL; lib++)
		{
			luaL_requiref(lua_state, lib->name, lib->func, 1);
			lua_settop(lua_state, 0);
		}
	}
	lua_State* GetLuaState()
	{
		return lua_state;
	}
	void Open(const char* filename) // открываем файл с кодом (main.lua)
	{
		luaL_openlibs(lua_state);
		if (luaL_dofile(lua_state, filename))
		{
			const char* error = lua_tostring(lua_state, -1);
		}
	}
	void Close() // закрываем
	{
		lua_close(lua_state);
	}
	void Reg_int(int value, char* name)
	{
		lua_pushinteger(lua_state, value);
		lua_setglobal(lua_state, name);
	}

	void Reg_double(double value, char* name)
	{
		lua_pushnumber(lua_state, value);
		lua_setglobal(lua_state, name);
	}

	void Reg_bool(bool value, char* name)
	{
		lua_pushboolean(lua_state, value);
		lua_setglobal(lua_state, name);
	}
	void Reg_string(char* value, char* name)
	{
		lua_pushstring(lua_state, value);
		lua_setglobal(lua_state, name);
	}
	void Reg_function(lua_CFunction value, const char* name) // регистр нашей функции
	{
		lua_pushcfunction(lua_state, value);
		lua_setglobal(lua_state, name);
	}
	void Reg_metatable(lua_State* L, lua_CFunction value, const char* name, const char* type) {
		luaL_newmetatable(L, name);
		lua_pushcfunction(L, value);
		lua_setfield(L, -2, type);
		lua_pushvalue(L, -1);
		lua_setfield(L, -2, "__index");
	}
	int Get_int(int index) // берем числовой аргумент из функции
	{
		return (int)lua_tointeger(lua_state, index);
	}
	double Get_double(int index)
	{
		return lua_tonumber(lua_state, index);
	}
	char* Get_string(int index)
	{
		return (char*)lua_tostring(lua_state, index);
	}
	bool Get_bool(int index)
	{
		return lua_toboolean(lua_state, index);
	}
	void Return_int(int value) // возвращаем числовое значение из функции
	{
		lua_pushinteger(lua_state, value);
	}
	void Return_double(double value)
	{
		lua_pushnumber(lua_state, value);
	}
	void Return_string(char* value)
	{
		lua_pushstring(lua_state, value);
	}
	void Return_bool(int value)
	{
		lua_pushboolean(lua_state, value);
	}
	int Call_load() // вызываем при старте
	{
		lua_getglobal(lua_state, "Load");
		lua_call(lua_state, 0, 1);
		return 0;
	}
	int Call_update() // вызываем пока работает приложени€
	{
		lua_getglobal(lua_state, "Update");
		lua_call(lua_state, 0, 1);
		return 0;
	}
	int Call_draw()
	{
		lua_getglobal(lua_state, "Draw"); // вызываем после "Update"
		lua_call(lua_state, 0, 1);
		return 0;
	}

};
Lua lua;// lua экземпл€р