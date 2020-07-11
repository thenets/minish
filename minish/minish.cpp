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
	heroAnimation.AddState("idle_front", 3, 32, 0.2f, Rectangle{ 0, 0,  32, 32 }, Rectangle{ 100, 100, 32, 32 });
	heroAnimation.AddState("idle_left", 3, 32, 0.2f, Rectangle{ 0, 32, 32, 32 }, Rectangle{ 100, 100, 32, 32 });
	heroAnimation.AddState("idle_right", 3, 32, 0.2f, Rectangle{ 0, 64, 32, 32 }, Rectangle{ 100, 100, 32, 32 });
	heroAnimation.AddState("idle_back", 1, 32, 0.2f, Rectangle{ 0, 96, 32, 32 }, Rectangle{ 100, 100, 32, 32 });
	heroAnimation.AddState("walking_front", 9, 32, 0.07f, Rectangle{ 128, 0,  32, 32 }, Rectangle{ 100, 100, 32, 32 });
	heroAnimation.AddState("walking_left", 9, 32, 0.07f, Rectangle{ 128, 32, 32, 32 }, Rectangle{ 100, 100, 32, 32 });
	heroAnimation.AddState("walking_right", 9, 32, 0.07f, Rectangle{ 128, 64, 32, 32 }, Rectangle{ 100, 100, 32, 32 });
	heroAnimation.AddState("walking_back", 9, 32, 0.07f, Rectangle{ 128, 96, 32, 32 }, Rectangle{ 100, 100, 32, 32 });
	

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(GRAY);

		if (IsKeyDown(KEY_UP))
			heroAnimation.SetState("walking_back");
		if (IsKeyDown(KEY_DOWN))
			heroAnimation.SetState("walking_front");
		if (IsKeyDown(KEY_LEFT))
			heroAnimation.SetState("walking_left");
		if (IsKeyDown(KEY_RIGHT))
			heroAnimation.SetState("walking_right");
		if (IsKeyUp(KEY_UP) and IsKeyUp(KEY_DOWN) and IsKeyUp(KEY_LEFT) and IsKeyUp(KEY_RIGHT))
			heroAnimation.SetState("idle_front");
		heroAnimation.Render();

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
