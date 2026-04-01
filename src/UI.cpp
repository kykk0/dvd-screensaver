#include "UI.h"

UI::UI(std::shared_ptr<Logo> logo) : _logo(logo) {
}

void UI::Draw() {
    ImGui::Begin("DVD Settings");

    int currentItem = _logo->GetCurrentLogoIndex();
    if (ImGui::Combo("Logo Type", &currentItem, _logoNames, IM_ARRAYSIZE(_logoNames))) {
        _logo->SetCurrentLogoIndex(currentItem);
    }

    ImGui::SliderFloat("Speed X", _logo->GetSpeedX(), -10.0f, 10.0f);
    ImGui::SliderFloat("Speed Y", _logo->GetSpeedY(), -10.0f, 10.0f);

    ImGui::SliderFloat("Scale", _logo->GetScale(), 0.1f, 3.0f);

    ImGui::ColorEdit3("Color", _logo->GetColor());

    if (ImGui::Button("Reset Position")) {
        _logo->ResetPosition();
    }

    ImGui::End();
}
