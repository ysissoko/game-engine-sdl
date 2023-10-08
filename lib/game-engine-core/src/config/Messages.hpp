#pragma once

namespace core::config::messages {
    namespace errors {
        // Errors
        constexpr const char* LOAD_CONFIG_PATH="Configuration file path not specified or incorrect. Please pass the CONFIG_PATH env variable on the command line";
        constexpr const char* INIT_SDL="Error initializing SDL";
        constexpr const char* INIT_WINDOW="Error initializing window";
        constexpr const char* INIT_RENDERER="Error initializing renderer";
    }
}
