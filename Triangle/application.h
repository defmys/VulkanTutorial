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
    void setExePath(const std::string& exePath);
    void setFramebufferResized(bool resized) { m_framebufferResized = resized; }
    void run();

private:
    void initVulkan() ;
    void mainLoop();
    void drawFrame();
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
    VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
    VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
    VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);
    void createSwapChain();

    // image view
    void createImageViews();

    void createGraphicsPipline();

    // shader
    VkShaderModule createShaderModule(const std::vector<char>& code);

    // render pass
    void createRenderPass();

    // framebuffer
    void createFramebuffers();

    // command buffer
    void createCommandPool();
    void createCommandBuffers();
    void recordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);

    // sychronization
    void createSyncObjects();

    // swap chain recreation
    void recreateSwapChain();
    void cleanupSwapChain();

    // vertex buffer
    void createVertexBuffer();
    uint32_t findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties);
    void createBuffer(VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, VkBuffer& buffer, VkDeviceMemory& bufferMemory);
    void copyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size);

    // index buffer
    void createIndexBuffer();

    // descriptor layout
    void createDescriptorSetLayout();

    // uniform buffers
    void createUniformBuffers();
    void updateUniformBuffer(uint32_t currentImage);

    // descriptor sets
    void createDescriptorPool();
    void createDescriptorSets();
    void updateDescriptorSets();

    void createTextureImage();
    void createImage(uint32_t width, uint32_t height, VkFormat format, VkImageTiling tiling, VkImageUsageFlags usage, VkMemoryPropertyFlags properties, VkImage& image, VkDeviceMemory& imageMemory);

    VkCommandBuffer beginSingleTimeCommands();
    void endSingleTimeCommands(VkCommandBuffer commandBuffer);
    void transitionImageLayout(VkImage image, VkFormat format, VkImageLayout oldLayout, VkImageLayout newLayout);
    
private:
    std::string m_exePath;

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

    VkSwapchainKHR m_swapChain;
    std::vector<VkImage> m_swapChainImages;
    VkFormat m_swapChainImageFormat;
    VkExtent2D m_swapChainExtent;
    std::vector<VkImageView> m_swapChainImageViews;

    VkRenderPass m_renderPass;
    VkDescriptorSetLayout m_descriptorSetLayout;
    VkPipelineLayout m_pipelineLayout;
    VkPipeline m_graphicsPipeline;

    std::vector<VkFramebuffer> m_swapChainFramebuffers;
    VkCommandPool m_commandPool;
    std::vector<VkCommandBuffer> m_commandBuffers;

    std::vector<VkSemaphore> m_imageAvailableSemaphores;
    std::vector<VkSemaphore> m_renderFinishedSemaphores;
    std::vector<VkFence> m_inflightFences;

    uint32_t m_currentFrame = 0;
    bool m_framebufferResized = false;

    VkBuffer m_vertexBuffer;
    VkDeviceMemory m_vertexBufferMemory;
    VkBuffer m_indexBuffer;
    VkDeviceMemory m_indexBufferMemory;
    
    std::vector<VkBuffer> m_uniformBuffers;
    std::vector<VkDeviceMemory> m_uniformBuffersMemory;

    VkDescriptorPool m_descriptorPool;
    std::vector<VkDescriptorSet> m_descriptorSets;

    VkImage m_textureImage;
    VkDeviceMemory m_textureImageMemory;
};