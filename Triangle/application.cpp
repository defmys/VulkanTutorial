#include "application.h"

#include <stdexcept>
#include <vector>

void HelloTriangleApplication::run()
{
    initVulkan();
    mainLoop();
    cleanUp();
}

void HelloTriangleApplication::initVulkan()
{
    if (m_initialized)
    {
        return;
    }

    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    m_pWindow = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);

    createInstance();

    m_initialized = true;
}

void HelloTriangleApplication::mainLoop()
{
    while(m_pWindow && !glfwWindowShouldClose(m_pWindow))
    {
        glfwPollEvents();
    }
}

void HelloTriangleApplication::cleanUp()
{
    vkDestroyInstance(m_instance, nullptr);

    if (m_pWindow)
    {
        glfwDestroyWindow(m_pWindow);
        m_pWindow = nullptr;
    }
    glfwTerminate();
}

void HelloTriangleApplication::createInstance()
{
    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Hello Triangle";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    std::vector<const char*> expectedExtensions;
    for (uint32_t i = 0; i < glfwExtensionCount; ++i)
    {
        const char* extension = glfwExtensions[i];
        if (extension)
        {
            expectedExtensions.push_back(extension);
        }
    }
    expectedExtensions.push_back(VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME);

    createInfo.enabledExtensionCount = expectedExtensions.size();
    createInfo.ppEnabledExtensionNames = expectedExtensions.data();
    createInfo.enabledLayerCount = 0;
    createInfo.flags = VK_KHR_portability_enumeration;

    VkResult result = vkCreateInstance(&createInfo, nullptr, &m_instance);
    if (result != VK_SUCCESS)
    {
        throw std::runtime_error("failed to create instance!");
    }
}
