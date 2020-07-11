#pragma once

#include <vector>
#include <raylib.h>

namespace Ded {
	class Texture
	{
		int textureScale;
		const char* textureFilePath;
		Texture2D texture;

	public:
		Texture(const char* a_textureFilePath, int a_textureScale);
		int GetScale();
		Texture2D* GetTexture();
	};

	// --

	struct AnimationState
	{
		const char* name;
		int totalOfFrames;
		int jumpSizeInPixels;
		float frameSkipTime;
		::Rectangle sourceRec;
		::Rectangle destRec;
	};
	class Animation
	{
		Ded::Texture* texture;
		int textureScale;
		int currentFrame;
		Ded::AnimationState* currentState;
		float deltaTime;
		std::vector<Ded::AnimationState> statesList;

	public:
		Animation(Ded::Texture* a_texture);
		void SetState(const char* a_name);
		Ded::AnimationState* GetState();
		void AddState(const char* a_name, int a_totalOfFrames, int a_jumpSizeInPixels, float a_frameSkipTime, ::Rectangle a_sourceRec, ::Rectangle a_destRec);
		void Render();
	};

}