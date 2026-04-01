#ifndef LOGO_H
#define LOGO_H

#include "DrawableObject.h"
#include <vector>
#include <string>
#include <optional>

class Logo : public DrawableObject {
    std::vector<sf::Texture> _textures;
    std::optional<sf::Sprite> _sprite;

    int _currentLogoIndex = 0;
    float _speedX;
    float _speedY;
    float _scale;
    float _color[3];
    sf::Vector2f _startPos;

public:
    Logo(const std::vector<std::string> &texturePaths, float speedX, float speedY, float scale, const float color[3]);

    void Update(int windowWidth, int windowHeight) override;

    void Draw(sf::RenderTarget &target) override;

    void ResetPosition();

    int &GetCurrentLogoIndex() { return _currentLogoIndex; }

    void SetCurrentLogoIndex(int index);

    float *GetSpeedX() { return &_speedX; }
    float *GetSpeedY() { return &_speedY; }

    float *GetScale() { return &_scale; }

    void ApplyScale();

    float *GetColor() { return _color; }
};

#endif // LOGO_H
