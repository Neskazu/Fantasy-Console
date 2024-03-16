#include "Colors.h"
#include "Engine.h"
#include "raylib.h"
#include "GraphicLua.h"


int main(int argc, char* argv[]) {
    const int screenWidth = 800;
    const int screenHeight = 450;

    //Init raylib
    InitWindow(screenWidth, screenHeight, "Your Game Title");
    SetTargetFPS(60);

    // Init lua + lua func
    lua.Init();
    lua.Reg_function(LuaDrawCircle, "DrawCircle"); // Func register
    lua.Reg_function(LuaPlaceSprite, "PlaceSprite");
    lua.Reg_function(LuaPlaceTile, "PlaceTile");
    lua.Reg_function(LuaDrawPixel, "DrawPixel");

    lua.Open("main.lua");
    lua.Call_load();
    // Main Loop
    while (!WindowShouldClose()) {
        // Update
        lua.Call_update();

        // Draw
        ClearBackground(DARKGRAY);
        BeginDrawing();
        lua.Call_draw();
        EndDrawing();
    }

    // End
    lua.Close();
    CloseWindow();
    return 0;
}