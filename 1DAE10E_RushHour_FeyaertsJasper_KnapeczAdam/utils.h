#pragma once
#include "structs.h"
#include <vector>

namespace utils
{

	const float g_Pi{ 3.1415926535f };

#pragma region OpenGLDrawFunctionality
	void ClearBackground(float r, float g, float b);
	void ClearBackground();
	// Choose a floating point value for each color component between 0.0f and 1.0f. The a (alpha) is optional.
	// Usage: SetColor(1.0f, 0.0f, 0.0f); set the drawing color to red
	void SetColor(float r, float g, float b, float a = 1);
	// Pass a Color4f object to the function
	void SetColor(const Color4f& color);

	// Draws a line by connecting the two points specified by (x1,y1) and (x2,y2)
	void DrawLine(float x1, float y1, float x2, float y2, float lineWidth = 1.0f);
	// Draws a line by connecting the two points specified by p1 and p1
	void DrawLine(const Point2f& p1, const Point2f& p2, float lineWidth = 1.0f);

	void DrawTriangle(const Point2f& p1, const Point2f& p2, const Point2f& p3, float lineWidth = 1);
	void FillTriangle(const Point2f& p1, const Point2f& p2, const Point2f& p3);
	void DrawRect(float left, float bottom, float width, float height, float lineWidth = 1.0f);
	void DrawRect(const Point2f& bottomLeft, float width, float height, float lineWidth = 1.0f);
	void DrawRect(const Rectf& rect, float lineWidth = 1.0f);
	void FillRect(float left, float bottom, float width, float height);
	void FillRect(const Point2f& bottomLeft, float width, float height);
	void FillRect(const Rectf& rect);

	void DrawEllipse(float centerX, float centerY, float radX, float radY, float lineWidth = 1.0f);
	void DrawEllipse(const Point2f& center, float radX, float radY, float lineWidth = 1.0f);
	void DrawEllipse(const Ellipsef& ellipse, float lineWidth = 1.0f);
	void FillEllipse(float centerX, float centerY, float radX, float radY);
	void FillEllipse(const Ellipsef& ellipse);
	void FillEllipse(const Point2f& center, float radX, float radY);

	// Draws an arc. The angle parameters are in radians, not in degrees.
	void DrawArc(float centerX, float centerY, float radX, float radY, float fromAngle, float tillAngle, float lineWidth = 1.0f);
	// Draws an arc. The angle parameters are in radians, not in degrees.
	void DrawArc(const Point2f& center, float radX, float radY, float fromAngle, float tillAngle, float lineWidth = 1.0f);
	// Fills an arc. The angle parameters are in radians, not in degrees.
	void FillArc(float centerX, float centerY, float radX, float radY, float fromAngle, float tillAngle);
	// Fills an arc. The angle parameters are in radians, not in degrees.
	void FillArc(const Point2f& center, float radX, float radY, float fromAngle, float tillAngle);

	void DrawPolygon(const std::vector<Point2f>& vertices, bool closed = true, float lineWidth = 1.0f);
	void DrawPolygon(const Point2f* pVertices, size_t nrVertices, bool closed = true, float lineWidth = 1.0f);
	void FillPolygon(const std::vector<Point2f>& vertices);
	void FillPolygon(const Point2f* pVertices, size_t nrVertices);
#pragma endregion OpenGLDrawFunctionality

#pragma region TextureFunctionality

	struct Texture
	{
		GLuint id;
		float width;
		float height;
	};
	bool TextureFromFile(const std::string& path, Texture& texture);
	bool TextureFromString(const std::string& text, TTF_Font* pFont, const Color4f& textColor, Texture& texture);
	bool TextureFromString(const std::string& text, const std::string& fontPath, int ptSize, const Color4f& textColor, Texture& texture);
	void TextureFromSurface(const SDL_Surface* pSurface, Texture& textureData);
	void DrawTexture(const Texture& texture, const Point2f& dstBottomLeft, const Rectf& srcRect = {});
	void DrawTexture(const Texture& texture, const Rectf& dstRect, const Rectf& srcRect = {});
	void DeleteTexture(Texture& texture);
#pragma endregion TextureFunctionality

#pragma region CollisionFunctionality

#pragma endregion CollisionFunctionality

	namespace Color
	{
		const Color4f red{ 0.92f, 0.13f, 0.15f, 1.0f };
		const Color4f green{ 0.56f, 0.8f, 0.53f, 1.0f };
		const Color4f orange{ 0.96f, 0.52f, 0.16f, 1.0f };
		const Color4f turquoise{ 0.14f, 0.73f, 0.93f, 1.0f };
		const Color4f rose{ 0.94f, 0.49f, 0.63f, 1.0f };
		const Color4f purple{ 0.4f, 0.39f, 0.67f, 1.0f };
		const Color4f darkGreen{ 0.05f, 0.6f, 0.42f, 1.0f };
		const Color4f lightGray{ 0.84f, 0.85f, 0.85f, 1.0f };
		const Color4f lightYellow{ 0.98f, 0.89f, 0.76f, 1.0f };
		const Color4f yellow{ 1.0f, 0.95f, 0.33f, 1.0f };
		const Color4f brown{ 0.57f, 0.39f, 0.33f, 1.0f };
		const Color4f darkYellow{ 0.54f, 0.55f, 0.03f, 1.0f };
		const Color4f gold{ 0.98f, 0.83f, 0.01f, 1.0f };
		const Color4f lavender{ 0.63f, 0.5f, 0.73f, 1.0f };
		const Color4f blue{ 0.04f, 0.48f, 0.75f, 1.0f };
		const Color4f darkTeal{ 0.02f, 0.68f, 0.6f, 1.0f };

		const Color4f black{0, 0, 0, 1.0f};
		const Color4f white{1.0f, 1.0f, 1.0f, 1.0f};
		const Color4f gray{0.24f, 0.24f, 0.24f, 1.0f};

		const Color4f highlight{ 1.0f, 1.0f, 1.0f, 0.3f };
		const Color4f translucent{ 0.5f, 0.5f, 0.5f, 0.5f };
	};

}