#pragma once

#include "WindowConfig.hpp"

namespace core::config
{
    struct Config
    {
        explicit Config(YAML::Node yaml) : window{yaml["window"]}
        {
        }

        struct WindowConfig window;
    };
}
