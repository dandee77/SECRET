#include <raylib.h>
#include "ball.h"

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 600;

    Ball ball = Ball();

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "My first RAYLIB program!");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(DARKBROWN);
        ball.Update(); 
        ball.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}