set(TARGET_NAME main)
set(SOURCES main.cpp
        Config.cpp
        Window.cpp
        Logo.cpp
        UI.cpp)

add_executable(${TARGET_NAME}
        ${SOURCES})

#target_compile_options(${TARGET_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror)
target_compile_features(${TARGET_NAME} PRIVATE cxx_std_20)
target_link_libraries(${TARGET_NAME} PUBLIC ImGui-SFML::ImGui-SFML nlohmann_json::nlohmann_json)