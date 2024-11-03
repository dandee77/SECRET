#pragma once
#include <raylib.h>

class Window
{
private:
    Shader shader;
    RenderTexture2D target;
    Camera2D camera;

public:
    Window();
    void Run();
    ~Window();
};