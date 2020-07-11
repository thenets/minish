#include "Ded.h"

Ded::Texture::Texture(const char* a_textureFilePath, int a_textureScale)
{
	textureScale = a_textureScale;
	textureFilePath = a_textureFilePath;

	// Resize image and create texture
	auto textureImage = LoadImage(textureFilePath);
	ImageResizeNN(&textureImage, textureImage.width * textureScale, textureImage.height * textureScale);
	texture = LoadTextureFromImage(textureImage);
}

int Ded::Texture::GetScale()
{
	return textureScale;
}

Texture2D* Ded::Texture::GetTexture()
{
	return &texture;
}
