#pragma once
#include <raylib.h>
#include "game.h"
#include "mainMenu.h"
#include "gameScene.h"

class Window
{
private:
    Shader shader;
    RenderTexture2D target;
    Camera2D camera;
    Game game;

public:
    Window();
    void Run();
    ~Window();
};