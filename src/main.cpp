#include <raylib.h>
#include "game.h"

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 600;

    

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "My first RAYLIB program!");
    SetTargetFPS(60);
    
    //add game class
    Game game;
    while (!WindowShouldClose())
    {
        BeginDrawing();

        //Update
        game.Update();
        ClearBackground(GREEN);
        //Draw
        game.Draw();
        

        EndDrawing();
    }

    CloseWindow();
    return 0;
}