# Attention: Les runners GitHub fournissent généralement CMake 3.x
# Fixe une version minimale compatible (évite l'échec sur CI)
cmake_minimum_required(VERSION 3.20)
project(GameEngine)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "bin/$<CONFIGURATION>")

# Option unique pour activer/désactiver l'Editor
option(BUILD_EDITOR "Construire l'exécutable Editor" ON)



file(GLOB_RECURSE ENGINE_SOURCES
        core/*.cpp
        core/*.h
)

# Crée la librairie Engine à partir du dossier core
add_library(Engine STATIC ${ENGINE_SOURCES})
target_include_directories(Engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/core)

# GLM (disponible pour les cibles qui suivent)
include(FetchContent)
FetchContent_Declare(glm GIT_REPOSITORY https://github.com/g-truc/glm.git GIT_TAG 1.0.1)
FetchContent_MakeAvailable(glm)


# ImGui (sera lié à Engine)
add_subdirectory(thirdparty/imgui)

# SDL3 (sera lié à Engine)
add_subdirectory(thirdparty/sdl EXCLUDE_FROM_ALL)

# Lier toutes les dépendances tierces directement à la librairie Engine
target_link_libraries(Engine
        PUBLIC
        glm::glm
        ImGui::imgui
        SDL3::SDL3
)

# Cible Editor (optionnelle)
if(BUILD_EDITOR)
    add_executable(Editor
            editor/main.cpp
            editor/Editor.cpp
    )
    target_include_directories(Editor PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/editor)
    target_link_libraries(Editor PRIVATE Engine)
endif()

# Cible Runtime (toujours construite)
add_executable(Runtime
        runtime/main.cpp
        runtime/Runtime.cpp
)
target_include_directories(Runtime PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/runtime)
target_link_libraries(Runtime PRIVATE Engine)