#pragma once

#include <exception>

namespace core::exception {
    class EngineException : public std::exception {
        public:
            explicit EngineException(const char* msg) : msg{msg} {

            }

            const char *what() const noexcept override {
                return msg;
            }

        private:
            const char* msg{nullptr};
    };
}
