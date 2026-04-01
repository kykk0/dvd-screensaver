#ifndef DRAWABLE_OBJECT_H
#define DRAWABLE_OBJECT_H

#include <SFML/Graphics.hpp>

class DrawableObject {
public:
    virtual ~DrawableObject() = default;

    virtual void Update(int windowWidth, int windowHeight) = 0;

    virtual void Draw(sf::RenderTarget &target) = 0;
};

#endif // DRAWABLE_OBJECT_H
