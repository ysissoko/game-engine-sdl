
#pragma once

#include "EngineException.hpp"
#include "config/Messages.hpp"

namespace core::exception {
    class WindowInitException : public EngineException {
        public:
            explicit WindowInitException() : EngineException(core::config::messages::errors::INIT_WINDOW) {

            }
    };
}
