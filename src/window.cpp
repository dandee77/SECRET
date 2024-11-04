#include "window.h"


Window::Window()
{   
    //SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800, 450, "SECRET");
    SetTargetFPS(60);
    //SetExitKey(KEY_NULL);

    camera = {0};
    camera.target = (Vector2){0, 0};
    camera.offset = (Vector2){GetScreenWidth()/2.0f, GetScreenHeight()/2.0f};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    game = Game();
    auto mainMenuScene = std::make_shared<MainMenuScene>();

    // Set up the callback to handle scene switching 
    mainMenuScene->onSwitchScene = [this](std::shared_ptr<Scene> newScene) {
        game.setScene(newScene);
    };

    // Set the initial scene
    game.setScene(mainMenuScene);
}

void Window::Run()
{
    while (!WindowShouldClose())
    {
        game.update(GetFrameTime());

        BeginDrawing();

            ClearBackground(RAYWHITE);
            DrawFPS(10, 10);
            game.draw();

        EndDrawing();
    }
}

Window::~Window()
{
    CloseWindow();
}