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

    lua.Open("main.lua");
    lua.Call_load();
    //test tiles
    Image image = LoadImage("Resources/Textures/grass03.png");     // Loaded in CPU memory (RAM)
    Texture2D texture = LoadTextureFromImage(image);          // Image converted to texture, GPU memory (VRAM)
    UnloadImage(image);
    //test
    // Main Loop
    while (!WindowShouldClose()) {
        // Update
        lua.Call_update();

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);
        lua.Call_draw();
        //draw tile
        Rectangle srcRect = { 0, 0, 50, 50 };
        Vector2 origin = { 0, 0 };
        for (int i = 0; i < 500; i += 50)
        {
            Rectangle destRect = { i, 0, 50, 50 };
            DrawTexturePro(texture, srcRect, destRect, origin, 0, WHITE);
        }
        
        EndDrawing();
    }

    // End
    lua.Close();
    CloseWindow();
    return 0;
}