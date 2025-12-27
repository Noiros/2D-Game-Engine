cmake_minimum_required(VERSION 3.16)

# ImGui core (no backends included here)
# This CMakeLists builds a static library target `imgui` and an ALIAS `ImGui::imgui`.

set(IMGUI_DIR ${CMAKE_CURRENT_LIST_DIR})

add_library(imgui STATIC
        imgui.cpp
        imgui_draw.cpp
        imgui_tables.cpp
        imgui_widgets.cpp
        imgui_demo.cpp
        backends/imgui_impl_sdl3.cpp
        backends/imgui_impl_opengl3.cpp
)
target_include_directories(imgui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(imgui PUBLIC SDL3::SDL3)
add_library(ImGui::imgui ALIAS imgui)

target_include_directories(imgui PUBLIC ${IMGUI_DIR})

## Note:
## Backend sources (SDL2/SDL3, OpenGL, Vulkan, etc.) are NOT added here to avoid
## configuration errors when backend files are absent from the repository.
## If you later add specific backends, extend IMGUI_SOURCES conditionally.

target_compile_features(imgui PUBLIC cxx_std_17)
