#include "Window.h"
#include "Config.h"

int main() {
    setlocale(LC_ALL, "");

    Config config = Config::Load("../config.json");

    Window window(config);
    window.Run();

    return 0;
}
