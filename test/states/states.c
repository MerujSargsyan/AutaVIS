#include <vector.h>
#include <raylib.h>

const float font_size = 12.0f;
const float rad_offset = 10.0f;
const float radius = 50;

void draw_states() {
    DrawCircle(250, 250, radius + rad_offset, BLACK);
    DrawCircle(250, 250, radius, LIGHTGRAY);

    Vector2 strSize = MeasureTextEx(GetFontDefault(), "q0", font_size, 1.0f);
    DrawText("q0", 250 - strSize.x, 250 - strSize.y, 20, BLACK);

    DrawCircle(100, 60, radius + rad_offset, BLACK);
    DrawCircle(100, 60, radius, LIGHTGRAY);

    strSize = MeasureTextEx(GetFontDefault(), "q1", font_size, 1.0f);
    DrawText("q1", 100 - strSize.x, 60 - strSize.y, 20, BLACK);
}

int main(void) {
    InitWindow(500, 500, "Accept States");

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
         {
             draw_states();
         }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
