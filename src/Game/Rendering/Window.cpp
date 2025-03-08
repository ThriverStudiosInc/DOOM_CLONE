#include "Window.h"

Window::Window(int width, int height, std::string title)
                : m_Width { width }, m_Height { height }, m_Title { title }
{
    if(!glfwInit())
    {
        slogLogConsole(Common::GetLogger(), SLOG_SEVERITY_ERROR, "Failed to init GLFW!");
        std::exit(-1);
    }
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
    
    m_Handle = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if(!m_Handle)
    {
        slogLogConsole(Common::GetLogger(), SLOG_SEVERITY_ERROR, "Failed to create the window!");
        std::exit(-1);
    }
    
    glfwSetWindowUserPointer(m_Handle, this);
    glfwMakeContextCurrent(m_Handle);
    glfwSetFramebufferSizeCallback(m_Handle, SizeCallback);
    
    if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
    {
        slogLogConsole(Common::GetLogger(), SLOG_SEVERITY_ERROR, "Failed to init OpenGL!");
        std::exit(-1);
    }
}

Window::~Window()
{
    if(m_Copy)
    {
        m_Copy = false;
        return;
    }

    glfwTerminate();
}

void Window::Show()
{
    glfwShowWindow(m_Handle);
}

void Window::Clear()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::Update()
{
    glfwPollEvents();
    glfwSwapBuffers(m_Handle);
}

void Window::SizeCallback(GLFWwindow* window, int w, int h)
{
    Window* win = (Window*)glfwGetWindowUserPointer(window);
    win->m_Width = w;
    win->m_Height = h;

    glViewport(0, 0, w, h);
}