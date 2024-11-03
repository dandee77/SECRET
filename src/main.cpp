#include <raylib.h>
#include "entity.h"

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 600;

    

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "My first RAYLIB program!");
    SetTargetFPS(60);
    
    Entity entity;

    while (!WindowShouldClose())
    {
        BeginDrawing();

        //Update

        ClearBackground(GREEN);
        //Draw
        entity.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}