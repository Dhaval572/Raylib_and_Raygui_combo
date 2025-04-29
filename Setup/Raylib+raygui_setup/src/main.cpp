#define RAYGUI_IMPLEMENTATION
#include <raylib.h>
#include <raygui.h>

int main()
{
    InitWindow(800, 600, " ");

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();

        

        EndDrawing();
    }

    CloseWindow();
    return 0;
}