#include <vector.h>
#include <raylib.h>

#define uint unsigned int

int main() {
    InitWindow(500, 500, "Hello World!");

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
