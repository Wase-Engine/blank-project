#include <unordered_map>
#include <string>
#include <typeinfo>

#include <engine.h>
#include <scene/scene.h>
#include <system/configuration.h>

#include <scenes/main_scene.h>
#include <scenes/second_scene.h>

int main()
{
	std::unordered_map<std::string, std::shared_ptr<wase::scene::Scene>> scenes = 
	{
		{ "main", std::make_shared<MainScene>() },
		{ "second", std::make_shared<SecondScene>() }
	};

	wase::system::Configuration config
	{ 
		"Wase Engine", 1280, 720, true,
		scenes, "main"
	};

	wase::Engine engine;
	engine.initialize(config);
	engine.run();
	engine.shutdown();
}