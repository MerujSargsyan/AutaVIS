#include <raylib.h>
#include <vector.h>

#define uint unsigned int

const float radius = 5.0f;

Vector2 lerp(Vector2 p1, Vector2 p2, float t) {
    Vector2 output = {0};
    output.x = (1 - t)*p1.x + t*p2.x;
    output.y = (1 - t)*p1.y + t*p2.y;
    return output;
}

void draw_points(vector* points) {
    for(int i = 0; i < points->size; i++) {
        Vector2 v = *(Vector2 *)points->arr[i];
        DrawCircle(v.x, v.y, 1.0f, BLACK);
    }
}

void draw_curve(float time, vector* points) {
    Vector2 start = {0};
    Vector2 end = {0};
    Vector2 third = {0};

    start = (Vector2){.x = 50, .y = 50};
    third = (Vector2){.x = 250, .y = 250};
    end = GetMousePosition();

    // two runner points
    Vector2 t1 = lerp(start, third, time);
    Vector2 t2 = lerp(third, end, time);

    DrawLineV(t1, t2, BLUE);
    DrawLineV(start, third, BLUE);
    DrawLineV(third, end, BLUE);

    // time point which draws the curve
    Vector2* tracer = malloc(sizeof(Vector2));

    // may be unnecessary
    Vector2 tracerTemp = lerp(t1, t2, time);
    tracer->x = tracerTemp.x;
    tracer->y = tracerTemp.y;

    vector_add(points, tracer);

    DrawCircle(start.x, start.y, radius, RED);
    DrawCircle(end.x, end.y, radius, BLUE);
    DrawCircle(third.x, third.y, radius, PURPLE);
    DrawCircle(t1.x, t1.y, radius, YELLOW);
    DrawCircle(t2.x, t2.y, radius, YELLOW);
    DrawCircle(tracer->x, tracer->y, radius, BLACK);

    draw_points(points);
}

int main() {
    float time = 0.0f;
    vector points = init_vector(10);

    SetTargetFPS(60);
    InitWindow(500, 500, "Hello World!");

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        {
            draw_curve(time, &points);
            time += 0.005f;
            if(time > 1.0f) time = 0.0f;
        }
        EndDrawing();
    }

    free_vector(&points);
    CloseWindow();
    return 0;
}
