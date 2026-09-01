#include <raylib.h>

int main(void) {
  InitWindow(800, 450, "Khukuri");
  SetTargetFPS(60);

  Vector2 position{400, 255};

  while (!WindowShouldClose()) {
    if (IsKeyDown(KEY_RIGHT))
      position.x += 4;
    if (IsKeyDown(KEY_LEFT))
      position.x -= 4;
    if (IsKeyDown(KEY_UP))
      position.y -= 4;
    if (IsKeyDown(KEY_DOWN))
      position.y += 4;
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("Hello, World!", position.x, position.y, 20, LIGHTGRAY);
    EndDrawing();
  }
  CloseWindow();
  return 0;
}
