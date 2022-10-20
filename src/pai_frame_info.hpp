#pragma once

#include "base/pai_camera.hpp"
#include "pai_game_object.hpp"

// lib
#include <vulkan/vulkan.h>

namespace pai
{

#define MAX_LIGHTS 100

    struct PointLight
    {
        glm::vec4 position{}; // ignore w
        glm::vec4 color{};    // w is intensity
    };

    struct GlobalUbo
    {
        glm::mat4 projection{1.f};
        glm::mat4 view{1.f};
        glm::mat4 inverseView{1.f};
        glm::vec4 ambientLightColor{1.f, 1.f, 1.f, .02f}; // w is intensity
        PointLight pointLights[MAX_LIGHTS];
        int numLights;
    };

    struct FrameInfo
    {
        int frameIndex;
        float frameTime;
        VkCommandBuffer commandBuffer;
        PaiCamera &camera;
        VkDescriptorSet globalDescriptorSet;
        PaiGameObject::Map &gameObjects;
    };
} // namespace pai
