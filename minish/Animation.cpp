#include <raylib.h>
#include "Ded.h"

Ded::Animation::Animation(Ded::Texture* a_texture, int a_currentState, ::Rectangle a_sourceRec, ::Rectangle a_destRec)
{
	texture = a_texture;
	sourceRec = a_sourceRec;
	destRec = a_destRec;
	textureScale = a_texture->GetScale();
	currentState = a_currentState;
	currentFrame = 0;
	deltaTime = 0;
}

void Ded::Animation::SetState(int a_stateID)
{
	currentState = a_stateID;
}

void Ded::Animation::Render()
{
	deltaTime += GetFrameTime();
	if (deltaTime >= 0.15f) {
		deltaTime = 0;
		currentFrame += 1;
		currentFrame = currentFrame % 3;
	}

	int nextFrameJump = currentFrame * destRec.width * textureScale;

	DrawTexturePro(
		*texture->GetTexture(),

		// Source position from texture
		Rectangle{
			(float)(sourceRec.x * textureScale + nextFrameJump),
			(float)(sourceRec.y * textureScale),
			(float)(sourceRec.width * textureScale),
			(float)(sourceRec.height * textureScale)
		},

		// Destination position on screen
		Rectangle{
			(float)(destRec.x * textureScale),
			(float)(destRec.y * textureScale),
			(float)(destRec.width * textureScale),
			(float)(destRec.height * textureScale)
		},

		// Pivot
		Vector2{ 0,0 },

		// Rotation degree
		0.0f,

		// Ilumination color
		RAYWHITE
	);
}
