# 🎮 VeEngine — 2D Pixel Art Game Engine (C++/SDL2)

VeEngine is a 2D game engine in C++ based on SDL2, designed for learning and building a modular and extensible foundation. It includes a small integrated 2D editor (ImGui) and a lightweight ECS architecture. The project ultimately aims to extend towards 3D.

## ✨ Main Features

- 🧩 **Lightweight ECS (Entity/Component System)**
    - Component ID management (`core/ECS.h`) with `ComponentBitset` and `ComponentArray`.
    - `GameObject` containing a component vector and helpers to retrieve/iterate them.
    - `SceneTree` to manage object lifecycle, updates, and depth/order-sorted rendering.

- 🛠️ **Integrated 2D Editor (EDITOR mode)**
    - **ImGui** integration via `SDL_Renderer` (see `core/Modules/RenderingServer.*`).
    - "Game Viewport" window with rendering to an **off-screen texture** (RTT) then display in the UI (`editor/Editor.cpp`).
    - Conditional launch via the `EDITOR` macro (disabled in runtime builds).

- 📦 **Resource Management**
    - `ResourcesManager` (SDL texture cache) to avoid multiple reloads.

- 🎮 **Input System**
    - `InputManager` with keyboard/gamepad action mapping (e.g., `MoveLeft`, `Shoot`, etc.).
    - Access to analog sticks, mouse, "held/pressed" states.

- 🧱 **Simple 2D Physics**
    - `PhysicsServer`: collider management and **AABB** (axis-aligned) collision detection + overlap queries and movement tests.

- 🖼️ **2D Rendering (SDL_Renderer)**
    - `RenderingServer`: window/renderer creation, clear/present, optional VSYNC.
    - In runtime mode: direct rendering. In editor mode: ImGui + viewport.

- 🧱 **Ready-to-use Components** (excerpts)
    - `Transform2D`, `Sprite2D`, `AnimatedSprite2D`, `Camera2D`, `Collider2D`, `CharacterMovement2D`, `TileMap2D`, `ObjectTileMap2D`, `LabelUI`.
    - Support for **Tiled**-style tilemaps (see `Tiled/` and `VeEngine/Assets/Maps/` folders).

- 🧪 **Included Gameplay Examples**
    - `VeEngine/Game/` folder with `Player`, `Enemies`, weapons, and projectiles to illustrate the ECS workflow.

- 🗺️ (Optional) **Dungeon Generation**
    - `modules/dungeon_gen` module (WIP) for future procedural features.

- 🚢 **Project Export System**
    - Currently: not finalized in code. The export pipeline is **WIP**. See below for status and temporary manual process.

## 🧭 Architecture (Overview)

- `core/Engine.*` — Engine entry point: setup, main loop (`Update`), singleton integration (SceneTree, InputManager, RenderingServer, ResourcesManager, PhysicsServer), clean shutdown management (SDL/ImGui/Editor).
- `core/Modules/SceneTree.*` — Maintains object list, per-frame updates, render order preparation (renderable component collection/sorting), and object factory by ID.
- `core/Modules/RenderingServer.*` — SDL initialization, renderer, VSYNC, ImGui (in EDITOR), rendering orchestration, and editor viewport.
- `core/Modules/InputManager.*` — Keyboard/gamepad action bindings, "held/pressed" states, stick axes, mouse.
- `core/Modules/ResourcesManager.*` — SDL texture loading/storage, cache.
- `core/Modules/PhysicsServer.*` — AABB collisions, overlap queries, collider registry management.
- `core/Components/*` — 2D and UI components (transform, sprites, cameras, collisions, movement, tilemaps…).
- `editor/Editor.*` — Off-screen rendering to texture + display in an ImGui "Game Viewport" window.
- `Game/*` — Example objects and logic (player, enemies, weapons, rooms…).

## 🚀 Quick Start

1) Required Tools
- Visual Studio / MSVC (`VeEngine.sln` solution)
- SDL2 + extensions (already included in `VeEngine/thirdparty`)
- C++20 (recent MSVC toolset)

2) Compilation
- Open `VeEngine.sln`.
- Define the `EDITOR` macro to enable the ImGui editor.
    - In MSVC: Project Properties → C/C++ → Preprocessor → `Preprocessor Definitions` → add `EDITOR` to definitions.
- Optional: define `VSYNC` to enable vertical sync.
- Launch in Debug/Release as needed.

3) Default Controls (examples)
- Keyboard: `WASD` to move, `Space` to shoot, `LShift` to dash.
- Gamepad: D-Pad to move, triggers/shoulders for actions, sticks for aiming.

## 🧪 Editor Mode (ImGui)

- In builds with `EDITOR`, the engine initializes ImGui (`ImGui_ImplSDL2` + `ImGui_ImplSDLRenderer2`).
- The game is first rendered to a target texture (Render Target) then displayed in the "Game Viewport" window.
- An ImGui demo window can be activated in the code to explore widgets.

## 📤 Project Export (Current State)

The "export system" is currently in design. At this stage, there is no dedicated automated export code in the repo yet. Suggested temporary manual process:
- Compile in Release without the `EDITOR` macro (runtime mode).
- Gather the executable and necessary asset folders (`VeEngine/Assets`, `Tiled/…`, etc.).
- Include required SDL2 DLLs (if not statically linked) present in `VeEngine/thirdparty/sdl/libs`.
- Test launch on a target machine.

Roadmap (planned):
- Export tool integrated into the editor (packaging of referenced assets + exe + options).
- Dependency profiling and selective copying.
- Optional build compression.

## 🗺️ Global Roadmap

- Additional editing tools: entity selection/editing, 2D gizmos, component inspector.
- Scene save/load (simple JSON/YAML format).
- Physics improvements (swept AABB, collision masks/categories, advanced triggers).
- Audio (SDL_mixer) and audio resource management.
- Scripting or data-driven logic.
- Integrated export/packaging pipelines.
- Progressive transition to a 3D foundation.

## 📚 Interesting Code References

- `core/ECS.h` — Component IDs, `MAX_COMPONENTS = 32`.
- `core/Modules/SceneTree.cpp` — Renderable component sorting before drawing, object factory by ID.
- `core/Modules/RenderingServer.cpp` — Dual runtime/editor path, clean ImGui initialization/shutdown.
- `editor/Editor.cpp` — Off-screen game rendering to texture + display in ImGui.
- `core/Modules/InputManager.cpp` — Keyboard/gamepad action mapping and states.
- `core/Modules/PhysicsServer.cpp` — AABB collisions, overlap queries, and movement tests.
- `core/Components/Sprite2D.*`, `AnimatedSprite2D.*`, `Camera2D.*`, `Collider2D.*`, `CharacterMovement2D.*`, `TileMap2D.*`.
