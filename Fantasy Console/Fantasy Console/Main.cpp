#include "Colors.h"
#include "Engine.h"
#include "raylib.h"
#include "GraphicLua.h"
#include "MemoryPool.h"
#include "Controls.h"
#include "ControlsLua.h"
#include "UserDataLua.h"

int main(int argc, char* argv[]) {
    const int screenWidth = 800;
    const int screenHeight = 450;
    const int poolSize = 40096;
    
    //Init memorypool
    MemoryPool* memoryPool = MemoryPool::getInstance(poolSize); 
    //Init Controls
    Controls* controls = Controls::getInstance();

    //Init raylib
    InitWindow(screenWidth, screenHeight, "Your Game Title");
    SetTargetFPS(120);

    // Init lua + lua func
    lua.Init();
    lua.Reg_function(LuaLoadTileSet, "LoadTileSet"); // Func register
    lua.Reg_function(LuaSetTile, "SetTile");
    lua.Reg_function(LuaRenderTileMap, "RenderTileMap");
    lua.Reg_function(LuaLoadTexture, "LoadTexture");
    lua.Reg_function(LuaDrawTexture, "DrawTexture");
    lua.Reg_function(LuaGetVirtualJoystick, "GetVirtualJoystick");
    lua.Reg_function(LuaGetVirtualMouse, "GetVirtualMouse");
    lua.Reg_function(LuaGetDeltaTime, "GetDeltaTime");
    lua.Reg_function(LuaCreateVector2, "CreateVector2");
    lua.Reg_function(LuaDrawTriangle, "DrawTriangle");
    lua.Reg_metatable(lua.GetLuaState(), LuaGetVector2, "Vector2MetaTable", "get");
    lua.Reg_metatable(lua.GetLuaState(), LuaSetVector2, "Vector2MetaTable", "set");
      
    lua.Open("main.lua");
    lua.Call_load();
    // Main Loop
    while (!WindowShouldClose()) {
        // Update
        lua.Call_update();
        //Input Update
        controls->UpdateVirtualJoystick();
        controls->UpdateVirtualMouse();
        // Draw
        ClearBackground(DARKGRAY);
        BeginDrawing();
        //test
        
        char* baseAddress = memoryPool->GetMemoryBlock();
        for (int i = 30005; i < 34096; i+=1)
        {
           // baseAddress[i] = i;
        }
        //
        lua.Call_draw();
        EndDrawing();

    }

    // End
    lua.Close();
    CloseWindow();
    return 0;
}