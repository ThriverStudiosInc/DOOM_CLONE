#pragma once

#include "Window.h"
#include "Shader.h"

class Renderer
{
public:
    Renderer() = default;
    Renderer(Window& window);
    ~Renderer();
    
    void Render();
    void Update();

private:
    Window* m_Window = nullptr;
    Shader m_MainShader;
};