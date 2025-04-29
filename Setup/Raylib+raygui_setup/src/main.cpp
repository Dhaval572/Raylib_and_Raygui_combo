#define RAYGUI_IMPLEMENTATION
#include <raylib.h>
#include <raygui.h>

int main()
{
    InitWindow(800, 600, " ");

    GuiLoadStyle("styles/style_genesis.rgs");
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        

        EndDrawing();
    }

    CloseWindow();
    return 0;
}