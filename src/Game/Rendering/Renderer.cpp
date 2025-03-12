#include "Renderer.h"

Renderer::Renderer(Window& window)
        : m_Window{&window}
{
    m_MainShader.Init("assets/shaders/default.glsl");
}

Renderer::~Renderer()
{
    m_MainShader.Destroy();
}

void Renderer::Render()
{
    m_MainShader.Bind();

    

    m_MainShader.Unbind();
}

void Renderer::Update()
{

}
