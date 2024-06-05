#include "Colors.h"
#include "Engine.h"
#include "raylib.h"
#include "GraphicLua.h"
#include "MemoryPool.h"
#include "Controls.h"
#include "ControlsLua.h"
#include "UserDataLua.h"
#include "PhysicLua.h"
#include "thread"

std::string currentLuaFile = "main.lua";
bool isExit;
void InitializeLua()
{
    // Init lua + lua func
    lua.Init();
    lua.Reg_function(LuaInitializeTileMap, "InitializeTileMap"); // Func register
    lua.Reg_function(LuaSetTile, "SetTile");
    lua.Reg_function(LuaRenderTileMap, "RenderTileMap");
    lua.Reg_function(LuaLoadTexture, "LoadTexture");
    lua.Reg_function(LuaDrawTexture, "DrawTexture");
    lua.Reg_function(LuaGetVirtualJoystick, "GetVirtualJoystick");
    lua.Reg_function(LuaGetVirtualMouse, "GetVirtualMouse");
    lua.Reg_function(LuaGetDeltaTime, "GetDeltaTime");
    lua.Reg_function(LuaCreateVector2, "CreateVector2");
    lua.Reg_function(LuaDrawTriangle, "DrawTriangle");
    lua.Reg_function(LuaCheckCollisionRecs, "CheckCollisionRecs");
    lua.Reg_function(LuaCheckCollisionCircles, "CheckCollisionCircles");
    lua.Reg_function(LuaCheckCollisionPointRec, "CheckCollisionPointRec");
    //Metatable for userData
    lua.Reg_metatable(lua.GetLuaState(), LuaGetVector2, "Vector2MetaTable", "get");
    lua.Reg_metatable(lua.GetLuaState(), LuaSetVector2, "Vector2MetaTable", "set");
}
void GameLoop(const string& luaFile)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    //Init Controls
    Controls* controls = Controls::getInstance();

    //Init raylib
    InitWindow(screenWidth, screenHeight, "Your Game Title");
    SetTargetFPS(120);

    InitializeLua();

    lua.Open(currentLuaFile.c_str());
    lua.Call_load();
    // Main Loop
    while (!WindowShouldClose()&&!isExit) {
        // Update
        lua.Call_update();
        //Input Update
        controls->UpdateVirtualJoystick();
        controls->UpdateVirtualMouse();
        // Draw
        ClearBackground(DARKGRAY);
        BeginDrawing();

        lua.Call_draw();
        EndDrawing();

    }
    lua.Close();
    CloseWindow();
    currentLuaFile = "";
}
void ProcessConsoleCommands()
{
    string input;
    while (true)
    {
        cout << "Enter  open 'Lua file name' to run or 'exit' to quit: ";
        getline(std::cin, input);
        if (input == "exit")
        {
            isExit = true;
        }
        else if (input.substr(0, 4) == "open" && input.length() > 5)
        {
            if (!isExit)
            {
                cout << "You should exit game before open new\n";
                continue;
            }
            currentLuaFile = input.substr(5);
            isExit = false;
        }
    }
}
int main(int argc, char* argv[]) 
{
     //Init memorypool
    const int poolSize = 40096;
    MemoryPool* memoryPool = MemoryPool::getInstance(poolSize);
    thread inputThread(ProcessConsoleCommands);

    
    while(true)
    {
        if (currentLuaFile!="")
        {
            GameLoop(currentLuaFile);
        }
    }

    //for (int i = 30005; i < 34096; i += 1)
    //{
    //    // baseAddress[i] = i;
    //}
    
    inputThread.join();

    return 0;
}