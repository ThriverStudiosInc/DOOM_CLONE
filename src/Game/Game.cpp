#include "Game.h"

Game::Game()
{
    m_Window = Window(800, 600, "DoomClone");
    m_Renderer = Renderer(m_Window);
}

Game::~Game()
{

}

void Game::Run()
{
    m_Window.SetClearColor(0.1f, 0.1f, 0.1f);
    m_Window.Show();
    while(m_Window.IsOpen())
    {
        m_Window.Clear();

        m_Renderer.Render();

        m_Window.Update();
    }
}