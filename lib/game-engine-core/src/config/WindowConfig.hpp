#pragma once

#include <yaml-cpp/yaml.h>

namespace core::config
{
    struct WindowConfig
    {

        explicit WindowConfig(YAML::Node yaml_node) : title{yaml_node["title"].as<std::string>()},
                                                      width{yaml_node["width"].as<int>()},
                                                      height{yaml_node["height"].as<int>()}
        {
        }

        std::string title{""};
        int width{0};
        int height{0};
    };
}
