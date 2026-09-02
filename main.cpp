#include <raylib.h>

void handlePlayerMovement(Rectangle *player, bool leftMovement,
                          bool rightMovement, float velocity, float dt);
int main(void) {
  InitWindow(800, 600, "Pong");
  SetTargetFPS(60);

  enum GameState { PLAYING, GAME_OVER };
  GameState state = GAME_OVER;
  Vector2 velocity{200, 300};

  Rectangle playerA{40, 250, 20, 100};
  Rectangle playerB{740, 250, 20, 100};

  Rectangle upperBoundary{0, 0, 800, 20};
  Rectangle lowerBoundary{0, 580, 800, 20};

  Vector2 circlePosition{390, 290};

  int playerAScore = 0;
  int playerBScore = 0;

  while (!WindowShouldClose()) {
    float dt = GetFrameTime();
    handlePlayerMovement(&playerA, IsKeyDown(KEY_W), IsKeyDown(KEY_S),
                         velocity.y, dt);
    handlePlayerMovement(&playerB, IsKeyDown(KEY_UP), IsKeyDown(KEY_DOWN),
                         velocity.y, dt);
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawRectangleRec(playerA, BLUE);
    DrawRectangleRec(playerB, GREEN);
    DrawRectangleRec(upperBoundary, PURPLE);
    DrawRectangleRec(lowerBoundary, PURPLE);
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
    if (!(player->y <= 20))
      player->y -= velocity * dt;
  }
  if (player->y <= 20) {
    player->y = 20;
  }
  if (rightMovement) {
    if (!(player->y >= 480))
      player->y += velocity * dt;
  }
  if (player->y >= 480) {
    player->y = 480;
  }
}
