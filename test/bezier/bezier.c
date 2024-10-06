#include <raylib.h>
#include <math.h>

#define uint unsigned int

const float radius = 5.0f;

Vector2 lerp(Vector2 p1, Vector2 p2, float t) {
    Vector2 output = {0};
    output.x = (1 - t)*p1.x + t*p2.x;
    output.y = (1 - t)*p1.y + t*p2.y;
    return output;
}

void draw_curve() {
    Vector2 start = {0};
    Vector2 end = {0};

    start.x = 50;
    start.y = 50;

    end = GetMousePosition();

    Vector2 mid = lerp(start, end, 0.5f);

    DrawLineV(start, end, BLACK);

    DrawCircle(start.x, start.y, radius, RED);
    DrawCircle(end.x, end.y, radius, BLUE);
    DrawCircle(mid.x, mid.y, radius, YELLOW);

}

int main() {
    SetTargetFPS(30);
    InitWindow(500, 500, "Hello World!");

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        draw_curve();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
