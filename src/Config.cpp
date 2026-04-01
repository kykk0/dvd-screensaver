#include "Config.h"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

Config Config::Load(const std::string &filename) {
    Config config;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open config file: " << filename << ". Using defaults.\n";
        return config;
    }

    nlohmann::json j;
    file >> j;

    config.windowWidth = j.value("WindowWidth", config.windowWidth);
    config.windowHeight = j.value("WindowHeight", config.windowHeight);
    config.fontPath = j.value("FontPath", config.fontPath);
    config.speedX = j.value("SpeedX", config.speedX);
    config.speedY = j.value("SpeedY", config.speedY);
    config.scale = j.value("Scale", config.scale);

    if (j.contains("LogoPaths") && j["LogoPaths"].is_array()) {
        config.logoPaths = j["LogoPaths"].get<std::vector<std::string> >();
    } else {
        config.logoPaths.resize(3);
    }

    if (j.contains("Color") && j["Color"].is_array() && j["Color"].size() == 3) {
        config.color[0] = j["Color"][0];
        config.color[1] = j["Color"][1];
        config.color[2] = j["Color"][2];
    }
    return config;
}
