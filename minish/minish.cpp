#include <raylib.h>

int main()
{
	const int WindowWidth = 800;
	const int WindowHeight = 800;

	InitWindow(WindowWidth, (int)WindowHeight, "Minish");

	SetTargetFPS(10);

	int scale = 4;

	// 32x24
	auto link_img = LoadImage("../assets/sprites-assets/hero.png");
	ImageResizeNN(&link_img, link_img.width * scale, link_img.height * scale);
	Texture2D link = LoadTextureFromImage(link_img);
	int link_frame = 0;

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(GRAY);

		link_frame += 1;
		link_frame = link_frame % 3;

		DrawTexturePro(
			link,
			Rectangle{ (float)(0 * scale + (link_frame * 32 * scale)), (float)(0 * scale), (float)(32 * scale), (float)(32 * scale) },
			Rectangle{ (float)(100 * scale), (float)(100 * scale), (float)(32 * scale), (float)(32 * scale) },
			Vector2{ 0,0 },
			0.0f,
			RAYWHITE
		);


		EndDrawing();
	}

	CloseWindow();

	return 0;
}