#include <raylib.h>

int main()
{
	const int WindowWidth = 800;
	const int WindowHeight = 800;

	InitWindow(WindowWidth, (int)WindowHeight, "Minish");

	SetTargetFPS(60);

	int scale = 4;

	// 32x24
	auto link_img = LoadImage("../assets/sprites/link.png");
	ImageResizeNN(&link_img, link_img.width * scale, link_img.height * scale);
	Texture2D link = LoadTextureFromImage(link_img);
	int link_frame = 0;

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(GRAY);



		DrawTexturePro(
			link,
			Rectangle{ (float)(12 * scale * link_frame), (float)(6 * scale), (float)(32 * scale), (float)(32 * scale) },
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