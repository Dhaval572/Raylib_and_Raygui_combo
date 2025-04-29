#define RAYGUI_IMPLEMENTATION
#include <raylib.h>
#include <raygui.h>

int main()
{
    InitWindow(600, 500, "Raygui Example");

    float sliderValue = 0.0f;
    float slideBarValue = 0.0f;

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("GuiSlide()", 200, 150, 40, RED);
        GuiSlider((Rectangle){200, 200, 200, 20}, "Slider", TextFormat("%.0f", sliderValue), &sliderValue, 0, 100);

        DrawText("GuiSlideBar()", 200, 250, 40, RED);
        GuiSliderBar((Rectangle){200, 300, 200, 20}, "SlideBar", TextFormat("%.0f", slideBarValue), &slideBarValue, 0, 100);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
