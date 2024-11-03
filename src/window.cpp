#include "window.h"

Window::Window()
{   
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800, 450, "SECRET");
    SetTargetFPS(60);
    SetExitKey(KEY_NULL);

    camera = {0};
    camera.target = (Vector2){0, 0};
    camera.offset = (Vector2){GetScreenWidth()/2.0f, GetScreenHeight()/2.0f};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
}

void Window::Run()
{
    while (!WindowShouldClose())
    {
        BeginDrawing();

            ClearBackground(DARKGRAY);

        EndDrawing();
    }
}

Window::~Window()
{
    CloseWindow();
}