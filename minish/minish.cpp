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
	auto heroAnimation = Ded::Animation(
		&texture,
		0,
		Rectangle{ 0, 0, 32, 32 },
		Rectangle{ 100, 100, 32, 32 }
	);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(GRAY);

		heroAnimation.Render();

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
