// Resize the object using GuiSlideBar()
#define RAYGUI_IMPLEMENTATION
#include <raylib.h>
#include <raygui.h>

int main()
{
    InitWindow(800, 600, "Resize Rectangle");

    float size = 300;
    Rectangle box = {300, 250, size, size};

    while (!WindowShouldClose())
    {
        GuiSliderBar((Rectangle){200, 100, 400, 20}, "Resize", TextFormat("%.0f", size), &size, 10, 300);

        box.width = box.height = size;
        box.x = 400 - size / 2;

        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawRectangleRec(box, BLUE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
