#include <iostream>
#include <chrono>

#include "Engine.hpp"
#include "config/Config.hpp"
#include "config/Messages.hpp"

#include "spdlog/spdlog.h"
#include "spdlog/cfg/env.h"   // support for loading levels from the environment variable

int main(void) {
    try {
        spdlog::cfg::load_env_levels(); // Log levels is configurable via env variable
        const char* yaml_file_path{nullptr};

        yaml_file_path = std::getenv("CONFIG_PATH");
        spdlog::debug("config path: {}", yaml_file_path);

        if (yaml_file_path == nullptr) {
            throw std::invalid_argument(core::config::messages::errors::LOAD_CONFIG_PATH);
        }

        YAML::Node yaml = YAML::LoadFile(yaml_file_path); // loading config file from env variable
        std::shared_ptr<core::config::Config> config{std::make_shared<core::config::Config>(yaml)};

        core::Engine engine{config};

        engine.start();
    } catch(const std::exception &e) {
        spdlog::error(e.what());
    }
    
    return 0;
}
