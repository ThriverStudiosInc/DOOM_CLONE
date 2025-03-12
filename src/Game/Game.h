#pragma once

#include "Rendering/Window.h"
#include "Rendering/Renderer.h"

class Game
{
public:
    Game();
    ~Game();

    void Run();

private:
    Window m_Window;
    Renderer m_Renderer;
};