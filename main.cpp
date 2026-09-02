#include <raylib.h>
#define GRAVITY 980
#define JUMP_SPEED 200

int main(void) {
  InitWindow(800, 600, "Khukuri");
  SetTargetFPS(60);

  Vector2 position{100, 300};
  Vector2 velocity{100, 20};

  Rectangle player{position.x, position.y, 50, 100};
  Rectangle ground{0, 400, 800, 200};
  while (!WindowShouldClose()) {
    float dt = GetFrameTime();
    if (IsKeyPressed(KEY_UP)) {
      velocity.y = -JUMP_SPEED;
    }
    velocity.y += GRAVITY * dt;
    player.y += velocity.y * dt;
    if (CheckCollisionRecs(player, ground) && velocity.y > 0) {
      velocity.y = 0;
      player.y = ground.y - player.height;
    }

    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawRectangleRec(player, BLUE);
    DrawRectangleRec(ground, GREEN);
    EndDrawing();
  }
  CloseWindow();
  return 0;
}
