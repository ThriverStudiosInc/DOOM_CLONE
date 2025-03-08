#pragma once

#include "Rendering/Window.h"

class Game
{
public:
    Game();
    ~Game();

    void Run();

private:
    Window m_Window;
};