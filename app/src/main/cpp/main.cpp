#include <raymob.h>

int main()
{
    InitWindow(0, 0, "SECRET");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(DARKGRAY);
        DrawText("I Like them young asf", 350, 320, 75, WHITE);
        EndDrawing();
    }

    CloseWindow();
    return  0;
}