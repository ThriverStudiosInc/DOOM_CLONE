#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>

#include "Common.h"

class Window
{
public:
    Window() = default;
    Window(int width, int height, std::string title);
    ~Window();

    void Show();
    void Clear();
    void Update();

    inline bool IsOpen() const { return !glfwWindowShouldClose(m_Handle); }

    inline int GetWidth() const { return m_Width; }
    inline int GetHeight() const { return m_Height; }
    inline GLFWwindow* GetHandle() const { return m_Handle; }

    inline void SetClearColor(float r, float g, float b) const { glClearColor(r, g, b, 1.0f); }

    inline void operator=(Window&& other)
    {
        m_Handle = other.m_Handle;
        m_Height = other.m_Height;
        m_Width = other.m_Width;
        m_Title = other.m_Title;
        
        glfwSetWindowUserPointer(m_Handle, this);

        other.m_Copy = true;
    }
private:
    bool m_Copy = false;
    GLFWwindow* m_Handle = nullptr;
    int m_Width, m_Height;
    std::string m_Title;

    static void SizeCallback(GLFWwindow* window, int w, int h);
};