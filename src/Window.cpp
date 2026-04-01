#include "Window.h"
#include "Logo.h"

Window::Window(const Config &config) : _config(config), _isRun(true) {
    _window.create(sf::VideoMode({
                       (unsigned int) config.windowWidth,
                       (unsigned int) config.windowHeight
                   }),
                   "Demo");
    _window.setFramerateLimit(60);

    (void) ImGui::SFML::Init(_window);
    ImGui::GetStyle().ScaleAllSizes(1.0f);
    ImGui::GetIO().FontGlobalScale = 1.5f;

    Initialize();
}

void Window::Initialize() {
    auto logo = std::make_shared<Logo>(_config.logoPaths, _config.speedX, _config.speedY, _config.scale, _config.color);

    _objects.push_back(logo);

    _ui = std::make_unique<UI>(logo);
}

void Window::Run() {
    while (_isRun) {
        sf::Time delta = _deltaClock.restart();
        ImGui::SFML::Update(_window, delta);

        UpdateUserInput();
        UpdateLogic();
        UpdateGui();
        Render();
    }
    _window.close();
    ImGui::SFML::Shutdown();
}

void Window::UpdateUserInput() {
    while (const std::optional event = _window.pollEvent()) {
        ImGui::SFML::ProcessEvent(_window, *event);
        if (event->is<sf::Event::Closed>()) {
            _isRun = false;
        }
    }
}

void Window::UpdateLogic() {
    for (auto &obj: _objects) {
        obj->Update(_window.getSize().x, _window.getSize().y);
    }
}

void Window::UpdateGui() {
    _ui->Draw();
}

void Window::Render() {
    _window.clear();

    for (auto &obj: _objects) {
        obj->Draw(_window);
    }

    ImGui::SFML::Render(_window);
    _window.display();
}
