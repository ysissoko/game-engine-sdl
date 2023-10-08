#pragma once

#include "renderer/Window.hpp"
#include "config/Config.hpp"
#include "config/Messages.hpp"

namespace core
{
    class Engine
    {
    public:
        Engine(std::shared_ptr<config::Config>);
        ~Engine();

        void start();

    private:
        std::shared_ptr<config::Config> config_{nullptr};
        std::shared_ptr<renderer::Window> window_{nullptr};
    };
}
