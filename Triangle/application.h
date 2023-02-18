#pragma once

#define VK_USE_PLATFORM_MACOS_MVK

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <vector>
#include <optional>


struct QueueFamilyIndices
{
    std::optional<uint32_t> graphicsFamily;
    std::optional<uint32_t> presentFamily;

    bool isComplete() 
    {
        return graphicsFamily.has_value() && presentFamily.has_value();
    };
};


struct SwapChainSupportDetails 
{
    VkSurfaceCapabilitiesKHR capabilities;
    std::vector<VkSurfaceFormatKHR> formats;
    std::vector<VkPresentModeKHR> presentModes;
};


class HelloTriangleApplication
{
public:
    void run();

private:
    void initVulkan() ;
    void mainLoop();
    void cleanUp() ;

    void createInstance();
    bool checkValidationLayerSupport();
    std::vector<const char*> getRequiredExtensions();

    // physical device
    void pickPhysicalDevice();
    int rateDeviceSuitability(VkPhysicalDevice device);
    bool isDeviceSuitable(VkPhysicalDevice device);
    bool checkDeviceExtensionSupport(VkPhysicalDevice device);

    // validation layers
    void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
    void setupDebugMessenger();
    VkResult CreateDebugUtilsMessengerEXT(const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator);
    void DestroyDebugUtilsMessengerEXT(const VkAllocationCallbacks* pAllocator);

    // queues
    QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);

    // logical device
    void createLogicalDevice();

    // surface
    void createSurface();

    // swap chain
    SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
    
private:
    const uint32_t WIDTH = 800;
    const uint32_t HEIGHT = 600;

    GLFWwindow* m_pWindow; 
    bool m_initialized = false;

    VkInstance m_instance;
    VkDebugUtilsMessengerEXT m_debugMessenger;

    VkPhysicalDevice m_physicalDevice = VK_NULL_HANDLE;

    VkDevice m_device;
    VkQueue m_graphicsQueue;
    VkQueue m_presentQueue;

    VkSurfaceKHR m_surface;
};