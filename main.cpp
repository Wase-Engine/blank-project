#include "game_scene.h"

#include <wase/core/engine.h>
#include <wase/core/managers/scene_manager.h>
#include <memory>

using namespace wase;

int main(int argc, char* argv[])
{
    // Initialize the engine, specify a title, the window position, the window size and additionally window flags 
    Engine::getInstance()->init("Blank project", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, NULL);

    // Load in the scenes
    SceneManager::addScene("game", std::make_shared<GameScene>());

    // Run the engine and let it open the window
    Engine::getInstance()->run("game");

    return 0;
}