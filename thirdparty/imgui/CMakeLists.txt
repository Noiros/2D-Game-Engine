cmake_minimum_required(VERSION 3.16)

# ImGui core (no backends included here)
# This CMakeLists builds a static library target `imgui` and an ALIAS `ImGui::imgui`.

set(IMGUI_DIR ${CMAKE_CURRENT_LIST_DIR})

set(IMGUI_SOURCES
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
    ${IMGUI_DIR}/imgui_demo.cpp
)

add_library(imgui STATIC ${IMGUI_SOURCES})
add_library(ImGui::imgui ALIAS imgui)

target_include_directories(imgui PUBLIC ${IMGUI_DIR})

## Note:
## Backend sources (SDL2/SDL3, OpenGL, Vulkan, etc.) are NOT added here to avoid
## configuration errors when backend files are absent from the repository.
## If you later add specific backends, extend IMGUI_SOURCES conditionally.

target_compile_features(imgui PUBLIC cxx_std_17)
