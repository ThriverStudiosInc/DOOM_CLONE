#include "Game.h"

Game::Game()
{
    m_Window = Window(800, 600, "DoomClone");
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



        m_Window.Update();
    }
}