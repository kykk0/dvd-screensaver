#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "imgui.h"
#include "imgui-SFML.h"
#include "DrawableObject.h"
#include "UI.h"
#include "Config.h"

class Window {
    sf::RenderWindow _window;

    sf::Clock _deltaClock;

    bool _isRun;

    Config _config;

    std::vector<std::shared_ptr<DrawableObject> > _objects;
    std::unique_ptr<UI> _ui;

    void Initialize();

    void UpdateUserInput();

    void UpdateLogic();

    void UpdateGui();

    void Render();

public:
    Window(const Config &config);

    void Run();
};

#endif //WINDOW_H
