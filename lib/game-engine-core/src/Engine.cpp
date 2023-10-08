#include "Engine.hpp"

namespace core
{
    Engine::Engine(std::shared_ptr<config::Config> config) : config_{config}, window_{renderer::Window::getInstance(config_->window)}
    {
        // TODO: init SDL
        if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        {
            throw std::runtime_error(config::messages::errors::INIT_SDL);
        }
    }

    void Engine::start()
    {
        // start the engine loop
        window_->render();
    }

    Engine::~Engine()
    {
        // TODO: Quit SDL
        SDL_Quit();
    }
}
