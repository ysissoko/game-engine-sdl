#pragma once

#include <config/WindowConfig.hpp>
#include <SDL2/SDL.h>

namespace core::renderer {
    constexpr int WINDOW_FLAGS = SDL_WINDOW_SHOWN;
    constexpr int RENDERER_FLAGS = SDL_RENDERER_ACCELERATED;

    constexpr int WINDOW_X = SDL_WINDOWPOS_UNDEFINED;
    constexpr int WINDOW_Y = SDL_WINDOWPOS_UNDEFINED;

    class Window {
        public:
            Window(config::WindowConfig config);
            ~Window();

            static std::shared_ptr<Window> getInstance(config::WindowConfig config) {
                if (nullptr == instance_) {
                    instance_ = std::make_shared<Window>(config);
                }

                return instance_;
            }

            void render();

        private:
            static std::shared_ptr<Window> instance_;
            SDL_Window* window_{nullptr};
            SDL_Renderer* renderer_{nullptr};

            void prepareScene(void);
            void handleEvents(void);
            void presentScene(void);

            void initWindow(config::WindowConfig config);
    };
}
