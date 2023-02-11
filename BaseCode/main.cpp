#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <cstdlib>


class HelloTriangleApplication
{
public:
    void run()
    {
        initVulkan();
        mainLoop();
        cleanUp();
    }

private:
    void initVulkan() 
    {
        if (m_initialized)
        {
            return;
        }

        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        m_pWindow = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);

        m_initialized = true;
    }

    void mainLoop() 
    {
        while(m_pWindow && !glfwWindowShouldClose(m_pWindow))
        {
            glfwPollEvents();
        }
    }

    void cleanUp() 
    {
        if (m_pWindow)
        {
            glfwDestroyWindow(m_pWindow);
            m_pWindow = nullptr;
        }
        glfwTerminate();
    }
    
private:
    const uint32_t WIDTH = 800;
    const uint32_t HEIGHT = 600;

    GLFWwindow* m_pWindow; 
    bool m_initialized = false;
};


int main()
{
    HelloTriangleApplication app;
    try
    {
        app.run();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}