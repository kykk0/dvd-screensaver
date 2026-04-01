#ifndef UI_H
#define UI_H

#include <memory>
#include "imgui.h"
#include "imgui-SFML.h"
#include "Logo.h"

class UI {
    std::shared_ptr<Logo> _logo;
    const char *_logoNames[3] = {"DVD", "BluRay", "CD"};

public:
    UI(std::shared_ptr<Logo> logo);

    void Draw();
};

#endif // UI_H
