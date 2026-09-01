#include <raylib.h>

int main(void) {
  enum GameState { JUMPING, FALLING, ON_GROUND, OVER };
  const int JUMP_HEIGHT{100};

  GameState state = ON_GROUND;

  InitWindow(800, 600, "Khukuri");
  SetTargetFPS(60);

  Vector2 position{100, 300};
  Vector2 fallVelocity{100, 20};
  Vector2 jumpVelocity{100, 500};

  Rectangle player{position.x, position.y, 50, 100};
  Rectangle ground{0, 400, 800, 200};
  while (!WindowShouldClose()) {
    float dt = GetFrameTime();
    if (IsKeyPressed(KEY_UP) && state != FALLING) {
      state = JUMPING;
      ;
    }
    if (state == JUMPING) {
      player.y -= jumpVelocity.y * dt;
      jumpVelocity.y -= 20;
      if (jumpVelocity.y == 0) {
        state = FALLING;
        jumpVelocity.y = 500;
      }
    }
    if (state == FALLING) {
      fallVelocity.y += 20;
      player.y += fallVelocity.y * dt;
    }
    if (CheckCollisionRecs(player, ground)) {
      fallVelocity.y = 20;
      state = ON_GROUND;
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
