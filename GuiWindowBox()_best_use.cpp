// Add setting menu in game demo
#define RAYGUI_IMPLEMENTATION
#include <raylib.h>
#include <raygui.h>

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Settings Panel Demo");

    GuiLoadStyle("styles/style_genesis.rgs");
    SetTargetFPS(60);

    Vector2 circlePos = {screenWidth / 2, screenHeight / 2};
    Color bgColor = BLACK;
    Color ballColor = RED;
    float colorR = 0.0f, colorG = 0.0f, colorB = 0.0f;
    float ballColorR = 65.0f, ballColorG = 65.0f, ballColorB = 148.0f;
    float circleSize = 50.0f;
    float circleSpeed = 5.0f;
    bool showSettings = true;
    bool circleVisible = true;

    while (!WindowShouldClose())
    {
        if (!showSettings)
        {
            if (IsKeyDown(KEY_RIGHT))
                circlePos.x += circleSpeed;
            if (IsKeyDown(KEY_LEFT))
                circlePos.x -= circleSpeed;
            if (IsKeyDown(KEY_UP))
                circlePos.y -= circleSpeed;
            if (IsKeyDown(KEY_DOWN))
                circlePos.y += circleSpeed;

            // Boundry checking
            if (circlePos.x + circleSize > screenWidth)
                circlePos.x = screenWidth - circleSize;

            if (circlePos.x - circleSize < 0)
                circlePos.x = circleSize;

            if (circlePos.y + circleSize > screenHeight)
                circlePos.y = screenHeight - circleSize;

            if (circlePos.y - circleSize < 0)
                circlePos.y = circleSize;
        }

        BeginDrawing();
        ClearBackground(bgColor);
        if (circleVisible)
        {
            DrawCircleV(circlePos, circleSize, ballColor);
            DrawText("Move with arrow keys", 10, 10, 20, WHITE);
        }

        // Settings
        if (showSettings)
        {
            if (GuiWindowBox((Rectangle){50, 50, 300, 400}, "SETTINGS PANEL"))
            {
                showSettings = false;
            }

            GuiLabel((Rectangle){100, 80, 200, 30}, "Background Color");
            GuiSliderBar((Rectangle){100, 110, 200, 20}, "RED", TextFormat("%d", (int)colorR), &colorR, 0, 255);
            GuiSliderBar((Rectangle){100, 140, 200, 20}, "GREEN", TextFormat("%d", (int)colorG), &colorG, 0, 255);
            GuiSliderBar((Rectangle){100, 170, 200, 20}, "BLUE", TextFormat("%d", (int)colorB), &colorB, 0, 255);
            bgColor = (Color){(unsigned char)colorR, (unsigned char)colorG, (unsigned char)colorB, 255};

            GuiLabel((Rectangle){100, 320, 200, 30}, "Ball Color");
            GuiSliderBar((Rectangle){100, 350, 200, 20}, "RED", TextFormat("%d", (int)ballColorR), &ballColorR, 0, 255);
            GuiSliderBar((Rectangle){100, 380, 200, 20}, "GREEN", TextFormat("%d", (int)ballColorG), &ballColorG, 0, 255);
            GuiSliderBar((Rectangle){100, 410, 200, 20}, "BLUE", TextFormat("%d", (int)ballColorB), &ballColorB, 0, 255);
            ballColor = (Color){(unsigned char)ballColorR, (unsigned char)ballColorG, (unsigned char)ballColorB, 255};

            GuiLabel((Rectangle){100, 200, 200, 30}, "Circle Settings");
            GuiSliderBar((Rectangle){100, 230, 200, 20}, "SIZE", TextFormat("%.0f", circleSize), &circleSize, 10, 100);
            GuiCheckBox((Rectangle){100, 260, 20, 20}, "Visible", &circleVisible);
            GuiSliderBar((Rectangle){100, 290, 200, 20}, "SPEED", TextFormat("%.1f", circleSpeed), &circleSpeed, 1, 15);
        }
        else
        {
            // Show button to reopen settings
            if (GuiButton((Rectangle){screenWidth - 150, 10, 140, 30}, "SETTINGS (F1)"))
            {
                showSettings = true;
            }
        }

        if (IsKeyPressed(KEY_F1))
            showSettings = !showSettings;

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
