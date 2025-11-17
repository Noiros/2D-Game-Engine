cmake_minimum_required(VERSION 4.0)
project(GameEngine)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "bin/$<CONFIGURATION>")

file(GLOB_RECURSE GAMEENGINE_SOURCES
        core/*.cpp
        editor/*.cpp
        runtime/*.cpp
        modules/*.cpp
        core/*.h
        editor/*.h
        runtime/*.h
        modules/*.h
)

add_executable(GameEngine
        main.cpp
        ${GAMEENGINE_SOURCES}
)

# GLM
include(FetchContent)
FetchContent_Declare(
        glm
        GIT_REPOSITORY https://github.com/g-truc/glm.git
        GIT_TAG 1.0.1
)
FetchContent_MakeAvailable(glm)

target_link_libraries(GameEngine PRIVATE glm::glm)

# ImGui
add_subdirectory(thirdparty/imgui)
target_link_libraries(GameEngine PRIVATE ImGui::imgui)

# SDL3
add_subdirectory(thirdparty/sdl EXCLUDE_FROM_ALL)
target_link_libraries(GameEngine PRIVATE SDL3::SDL3)