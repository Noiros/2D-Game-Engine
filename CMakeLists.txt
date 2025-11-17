cmake_minimum_required(VERSION 3.20)
project(GameEngine)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "bin/$<CONFIGURATION>")

option(EDITOR "Construire l'exécutable Editor" ON)


file(GLOB_RECURSE ENGINE_SOURCES
        core/*.cpp
        core/*.h
)
add_library(Engine SHARED ${ENGINE_SOURCES})
target_include_directories(Engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/core)


# GLM (disponible pour les cibles qui suivent)
include(FetchContent)
FetchContent_Declare(glm GIT_REPOSITORY https://github.com/g-truc/glm.git GIT_TAG 1.0.1)
FetchContent_MakeAvailable(glm)
target_link_libraries(Engine PUBLIC glm::glm)

# ImGui (sera lié à Engine)
add_subdirectory(thirdparty/imgui)
target_link_libraries(Engine PUBLIC ImGui::imgui)

# SDL3 (sera lié à Engine)
add_subdirectory(thirdparty/sdl EXCLUDE_FROM_ALL)
target_link_libraries(Engine PUBLIC SDL3::SDL3)



if(EDITOR)
    add_executable(Editor editor/Editor.cpp)
    target_include_directories(Editor PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/editor)
    target_link_libraries(Editor PRIVATE Engine)
else ()
    add_executable(Runtime runtime/Runtime.cpp)
    target_include_directories(Runtime PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/runtime)
    target_link_libraries(Runtime PRIVATE Engine)
endif ()


add_custom_command(TARGET Editor POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:SDL3::SDL3>
        $<TARGET_FILE_DIR:Editor>
)
