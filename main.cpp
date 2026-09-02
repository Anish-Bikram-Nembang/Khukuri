#include <raylib.h>

void handlePlayerMovement(Rectangle *player, bool leftMovement,
                          bool rightMovement, float velocity, float dt);
int main(void) {
  InitWindow(800, 600, "Pong");
  SetTargetFPS(60);

  enum GameState { PLAYING, GAME_OVER };
  GameState state = GAME_OVER;
  Vector2 velocity{200, 20};

  Rectangle playerA{350, 80, 100, 20};
  Rectangle playerB{350, 500, 100, 20};

  Vector2 circlePosition{390, 290};

  int playerAScore = 0;
  int playerBScore = 0;

  while (!WindowShouldClose()) {
    float dt = GetFrameTime();
    handlePlayerMovement(&playerA, IsKeyDown(KEY_A), IsKeyDown(KEY_D),
                         velocity.x, dt);
    handlePlayerMovement(&playerB, IsKeyDown(KEY_LEFT), IsKeyDown(KEY_RIGHT),
                         velocity.x, dt);
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawRectangleRec(playerA, BLUE);
    DrawRectangleRec(playerB, GREEN);
    DrawCircle(circlePosition.x, circlePosition.y, 10, RED);
    EndDrawing();
  }
  CloseWindow();
  return 0;
}
void checkAndUpdateScore() {}
void handlePlayerMovement(Rectangle *player, bool leftMovement,
                          bool rightMovement, float velocity, float dt) {
  if (leftMovement) {
    if (!(player->x <= 0))
      player->x -= velocity * dt;
  }
  if (player->x <= 0) {
    player->x = 0;
  }
  if (rightMovement) {
    if (!(player->x >= 700))
      player->x += velocity * dt;
  }
  if (player->x >= 700) {
    player->x = 700;
  }
}
