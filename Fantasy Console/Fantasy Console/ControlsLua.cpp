#include "ControlsLua.h"

Controls* controls = Controls::getInstance();
int LuaGetVirtualJoystick(lua_State* L)
{
    lua_pushboolean(L, controls->vJoystick.buttonLeft);
    lua_pushboolean(L, controls->vJoystick.buttonRight);
    lua_pushboolean(L, controls->vJoystick.buttonUp);
    lua_pushboolean(L, controls->vJoystick.buttonDown);
    lua_pushboolean(L, controls->vJoystick.buttonX);
    lua_pushboolean(L, controls->vJoystick.buttonB);
    lua_pushboolean(L, controls->vJoystick.buttonY);
    lua_pushboolean(L, controls->vJoystick.buttonA);
	return 8;
}

int LuaGetVirtualMouse(lua_State* L)
{
    lua_pushnumber(L, controls->vMouse.x);
    lua_pushnumber(L, controls->vMouse.y);
    lua_pushboolean(L, controls->vMouse.leftButton);
    lua_pushboolean(L, controls->vMouse.rightButton);
    return 4; 
}

int LuaGetDeltaTime(lua_State* L)
{
    float deltaTime = GetFrameTime();
    lua_pushnumber(L, deltaTime);
    return 1;
}

