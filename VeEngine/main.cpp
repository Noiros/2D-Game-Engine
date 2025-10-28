//#define EDITOR

#include "core/Engine.h"
#include "editor/Editor.h"
#include "Game/Game.h"
#include "runtime/Runtime.h"

int main(int argc, char* argv[])
{
    Engine engine;
    Engine::SetInstance(&engine);
    engine.Setup();

#ifdef EDITOR
    Editor editor;
    editor.Setup(&engine);
    
#else
    //Runtime game;
    //game.Setup(&engine);
    
    Game game;
    game.Start(&engine);

    

#endif
    engine.Run();

    return 0;
}
