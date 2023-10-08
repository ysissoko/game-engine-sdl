#pragma once

#include <array>
#include <yaml-cpp/yaml.h>

namespace core::config
{
    struct WindowConfig
    {

        explicit WindowConfig(YAML::Node yaml_node) : title{yaml_node["title"].as<std::string>()},
                                                      width{yaml_node["width"].as<int>()},
                                                      height{yaml_node["height"].as<int>()},
                                                      fillColor{yaml_node["fillColor"].as<std::array<uint8_t, 3>>()}
                                                      
        {
        }

        std::string title{""};
        int width{0};
        int height{0};

        std::array<uint8_t, 3> fillColor;
    };
}
