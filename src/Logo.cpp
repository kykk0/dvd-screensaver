#include "Logo.h"
#include <iostream>
#include <cmath>

Logo::Logo(const std::vector<std::string> &texturePaths, float speedX, float speedY, float scale, const float color[3])
    : _speedX(speedX), _speedY(speedY), _scale(scale) {
    _color[0] = color[0];
    _color[1] = color[1];
    _color[2] = color[2];
    _startPos = sf::Vector2f{0.f, 0.f};

    _textures.resize(texturePaths.size());
    for (size_t i = 0; i < texturePaths.size(); ++i) {
        if (!_textures[i].loadFromFile(texturePaths[i])) {
            std::cerr << "Failed to load texture: " << texturePaths[i] << "\n";
        }
    }

    if (!_textures.empty()) {
        _sprite.emplace(_textures[0]);
    }

    SetCurrentLogoIndex(0);
    ResetPosition();
}

void Logo::SetCurrentLogoIndex(int index) {
    if (index >= 0 && index < _textures.size() && _sprite.has_value()) {
        _currentLogoIndex = index;
        _sprite->setTexture(_textures[_currentLogoIndex], true);
        ApplyScale();
    }
}

void Logo::ApplyScale() {
    if (_sprite) _sprite->setScale(sf::Vector2f{_scale, _scale});
}

void Logo::ResetPosition() {
    if (_sprite) _sprite->setPosition(_startPos);
}

void Logo::Update(int windowWidth, int windowHeight) {
    if (!_sprite) return;

    _sprite->setColor(sf::Color(
        static_cast<std::uint8_t>(_color[0] * 255),
        static_cast<std::uint8_t>(_color[1] * 255),
        static_cast<std::uint8_t>(_color[2] * 255)
    ));
    ApplyScale();

    sf::FloatRect bounds = _sprite->getGlobalBounds();

    if (bounds.size.x >= windowWidth || bounds.size.y >= windowHeight) {
        return;
    }

    _sprite->move(sf::Vector2f{_speedX, _speedY});

    bounds = _sprite->getGlobalBounds();

    if (bounds.position.x <= 0) {
        _sprite->setPosition(sf::Vector2f{0.f, bounds.position.y});
        _speedX = std::abs(_speedX);
    } else if (bounds.position.x + bounds.size.x >= windowWidth) {
        _sprite->setPosition(sf::Vector2f{windowWidth - bounds.size.x, bounds.position.y});
        _speedX = -std::abs(_speedX);
    }

    if (bounds.position.y <= 0) {
        _sprite->setPosition(sf::Vector2f{bounds.position.x, 0.f});
        _speedY = std::abs(_speedY);
    } else if (bounds.position.y + bounds.size.y >= windowHeight) {
        _sprite->setPosition(sf::Vector2f{bounds.position.x, windowHeight - bounds.size.y});
        _speedY = -std::abs(_speedY);
    }
}

void Logo::Draw(sf::RenderTarget &target) {
    if (_sprite) target.draw(*_sprite);
}
