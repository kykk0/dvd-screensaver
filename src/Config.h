#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <vector>

struct Config {
    int windowWidth = 1280;
    int windowHeight = 720;
    std::string fontPath;
    std::vector<std::string> logoPaths;
    float speedX = 1.0f;
    float speedY = 1.0f;
    float scale = 1.0f;
    float color[3] = {1.0f, 0.0f, 0.0f};

    static Config Load(const std::string &filename);
};

#endif // CONFIG_H
