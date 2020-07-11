#include <iostream>
#include <raylib.h>
#include "Ded.h"

Ded::Animation::Animation(Ded::Texture* a_texture)
{
	texture = a_texture;
	textureScale = a_texture->GetScale();

	currentState = nullptr;
	currentFrame = 0;
	deltaTime = 0;
}

void Ded::Animation::SetState(const char* a_name)
{
	if (currentState != nullptr and currentState->name == a_name)
	{
		return;
	}
	for (unsigned int i = 0; i < statesList.size(); i++)
	{
		if (statesList[i].name == a_name)
		{
			currentState = &statesList[i];
			currentFrame = 0;
			return;
		}
	}
	std::cout << "[ERROR] DedEngine : SetState() state not found : " << a_name;
}

Ded::AnimationState* Ded::Animation::GetState()
{
	return nullptr;
}

void Ded::Animation::AddState(const char* a_name, int a_totalOfFrames, int a_jumpSizeInPixels, float a_frameSkipTime, ::Rectangle a_sourceRec, ::Rectangle a_destRec)
{
	auto state = new Ded::AnimationState;
	state->name = a_name;
	state->totalOfFrames = a_totalOfFrames;
	state->jumpSizeInPixels = a_jumpSizeInPixels;
	state->frameSkipTime = a_frameSkipTime;
	state->sourceRec = a_sourceRec;
	state->destRec = a_destRec;
	statesList.push_back(*state);
}

void Ded::Animation::Render()
{
	// Ignore is has no state
	if (statesList.empty()) return;

	deltaTime += GetFrameTime();
	if (deltaTime >= currentState->frameSkipTime) {
		deltaTime = 0;
		currentFrame += 1;
		currentFrame = currentFrame % currentState->totalOfFrames;
	}

	float nextFrameJump = currentFrame * currentState->destRec.width * textureScale;

	DrawTexturePro(
		*texture->GetTexture(),

		// Source position from texture
		Rectangle{
			(float)( (currentState->sourceRec.x * textureScale) + nextFrameJump),
			(float)(currentState->sourceRec.y * textureScale),
			(float)(currentState->sourceRec.width * textureScale),
			(float)(currentState->sourceRec.height * textureScale)
		},

		// Destination position on screen
		Rectangle{
			(float)(currentState->destRec.x * textureScale),
			(float)(currentState->destRec.y * textureScale),
			(float)(currentState->destRec.width * textureScale),
			(float)(currentState->destRec.height * textureScale)
		},

		// Pivot
		Vector2{ 0,0 },

		// Rotation degree
		0.0f,

		// Ilumination color
		RAYWHITE
	);
}
