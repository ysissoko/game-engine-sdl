#pragma once

#include "EngineException.hpp"
#include "config/Messages.hpp"

namespace core::exception {
    class RendererInitException : public EngineException {
        public:
            explicit RendererInitException() : EngineException(core::config::messages::errors::INIT_RENDERER) {

            }
    };
}
