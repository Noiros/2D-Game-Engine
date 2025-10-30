#define EDITOR

#include "imgui.h"
#include "core/Engine.h"
#include "game/Game.h"

#ifdef EDITOR
    #include "editor/Editor.h"
#else
    #include "runtime/Runtime.h"
#endif

int main(int argc, char* argv[])
{
    Engine engine;
    Engine::SetInstance(&engine);
    engine.Setup();

    Game game;
    game.Start(&engine);

#ifdef EDITOR
    Editor editor;
    Editor::SetInstance(&editor);
    editor.Setup(&engine);
    
#else
    //Runtime game;
    //game.Setup(&engine);
    

    

#endif
    engine.Run();

    return 0;
}
