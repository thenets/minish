#pragma once

#include <raylib.h>

namespace Ded {
	struct Texture
	{
		Texture(const char* a_textureFilePath, int a_textureScale);
		int GetScale();
		Texture2D* GetTexture();

	private:
		int textureScale;
		const char* textureFilePath;
		Texture2D texture;
	};

	// --

	struct Animation
	{
		Animation(Ded::Texture* a_texture, int a_currentState, ::Rectangle a_sourceRec, ::Rectangle a_destRec);
		void SetState(int a_stateID);
		void Render();

	private:
		Ded::Texture* texture;
		::Rectangle sourceRec;
		::Rectangle destRec;
		int textureScale;
		int currentFrame;
		int currentState;
		float deltaTime;
	};

}