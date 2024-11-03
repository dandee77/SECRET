#include "window.h"

int main()
{
    Window* window = new Window();
    window->Run();
    delete window;
}