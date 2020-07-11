#include <raylib.h>

#include "Ded.h"

int main()
{
	const int WindowWidth = 800;
	const int WindowHeight = 800;

	InitWindow(WindowWidth, (int)WindowHeight, "Minish");

	SetTargetFPS(60);
	float delta_time = 0;

	int scale = 4;

	// Import image and convert to texture
	auto texture = Ded::Texture("../assets/sprites-assets/hero.png", scale);

	// Create animation
	auto heroAnimation = Ded::Animation(&texture);
	heroAnimation.AddState("idle_front", 3, 32, 0.2f, Rectangle{ 32, 32,  32, 32 }, Rectangle{ 100, 100, 32, 32 });
	heroAnimation.AddState("idle_left", 3, 32, 0.2f, Rectangle{ 32, 64, 32, 32 }, Rectangle{ 100, 100, 32, 32 });
	heroAnimation.AddState("idle_right", 3, 32, 0.2f, Rectangle{ 32, 96, 32, 32 }, Rectangle{ 100, 100, 32, 32 });
	heroAnimation.AddState("idle_back", 1, 32, 0.2f, Rectangle{ 32, 128, 32, 32 }, Rectangle{ 100, 100, 32, 32 });
	heroAnimation.AddState("walking_front", 10, 32, 0.07f, Rectangle{ 128, 32,  32, 32 }, Rectangle{ 100, 100, 32, 32 });
	heroAnimation.AddState("walking_left", 10, 32, 0.07f, Rectangle{ 128, 64, 32, 32 }, Rectangle{ 100, 100, 32, 32 });
	heroAnimation.AddState("walking_right", 10, 32, 0.07f, Rectangle{ 128, 96, 32, 32 }, Rectangle{ 100, 100, 32, 32 });
	heroAnimation.AddState("walking_back", 10, 32, 0.07f, Rectangle{ 128, 128, 32, 32 }, Rectangle{ 100, 100, 32, 32 });
	const char* next_idle_state = "idle_front";
	
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(GRAY);

		if (IsKeyDown(KEY_UP)) {
			heroAnimation.SetState("walking_back");
			next_idle_state = "idle_back";
		}
		else if (IsKeyDown(KEY_DOWN)) {
			heroAnimation.SetState("walking_front");
			next_idle_state = "idle_front";

		}
		else if (IsKeyDown(KEY_LEFT)) {
			heroAnimation.SetState("walking_left");
			next_idle_state = "idle_left";

		}
		else if (IsKeyDown(KEY_RIGHT)) {
			heroAnimation.SetState("walking_right");
			next_idle_state = "idle_right";
		}
		if (IsKeyUp(KEY_UP) and IsKeyUp(KEY_DOWN) and IsKeyUp(KEY_LEFT) and IsKeyUp(KEY_RIGHT))
			heroAnimation.SetState(next_idle_state);
		heroAnimation.Render();

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
