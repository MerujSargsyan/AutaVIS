#include <vector.h>
#include <raylib.h>
#include <math.h>

int main() {
    SetTargetFPS(30);
    InitWindow(500, 500, "Hello World!");

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
