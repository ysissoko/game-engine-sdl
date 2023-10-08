#include "Window.hpp"

#include "exceptions/WindowInitException.hpp"
#include "exceptions/RendererInitException.hpp"

namespace core::renderer {
    std::shared_ptr<Window> Window::instance_ = nullptr;

    Window::Window(config::WindowConfig config) {
        // Create a sdl window
        initWindow(config);
    }

    void Window::initWindow(config::WindowConfig config) {
        window_ = SDL_CreateWindow(config.title.c_str(),
                        WINDOW_X, WINDOW_Y, config.width,
                        config.height, WINDOW_FLAGS);

        if (nullptr == window_)
            throw exception::WindowInitException();

        renderer_ = SDL_CreateRenderer(window_, -1, RENDERER_FLAGS);

        if (nullptr == renderer_) 
            throw exception::RendererInitException();
    }

    void Window::prepareScene(void)
    {
        SDL_SetRenderDrawColor(renderer_, 96, 128, 255, 255);
        SDL_RenderClear(renderer_);
    }

    void Window::presentScene(void)
    {
        SDL_RenderPresent(renderer_);
    }

    void Window::handleEvents(void)
    {
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    exit(0);
                    break;

                default:
                    break;
            }
        }
    }

    /**
     * @brief starts the render loop
     * 
     */
    void Window::render() {
        // event handling
        while (1)
        {
            prepareScene();

            handleEvents();

            presentScene();

            SDL_Delay(16);
        }
    }

    Window::~Window() {
        SDL_DestroyWindow(window_);
        window_ = nullptr;
    }
}
