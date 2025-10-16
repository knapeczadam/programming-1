// Knapecz, Adam - 1DAE11
#include "pch.h"
#include "Sprite.h"

Sprite::Sprite(const std::string& fileName, int nrCols, int nrRows, float frameSec, float scale)
	: m_Cols{nrCols}
	  , m_Rows{nrRows}
	  , m_FrameSec{frameSec}
	  , m_AccuSec{}
	  , m_ActFrame{}
	  , m_Scale{scale}
{
	utils::TextureFromFile(fileName, m_Texture);
}

Sprite::~Sprite()
{
	utils::DeleteTexture(m_Texture);
}

void Sprite::Update(float elapsedSec)
{
	m_AccuSec += elapsedSec;
	if (m_AccuSec >= m_FrameSec)
	{
		m_AccuSec -= m_FrameSec;
		++m_ActFrame %= (m_Rows * m_Cols);
	}
}

void Sprite::Draw(const Point2f& pos) const
{
	Rectf src;
	src.width = GetFrameWidth();
	src.height = GetFrameHeight();
	src.left = src.width * (m_ActFrame % m_Cols);
	src.bottom = src.height + src.height * (m_ActFrame / m_Cols);

	Rectf dst;
	dst.width = src.width * m_Scale;
	dst.height = src.height * m_Scale;
	dst.left = pos.x;
	dst.bottom = pos.y;
	utils::DrawTexture(m_Texture, dst, src);
}

float Sprite::GetFrameWidth() const
{
	return m_Texture.width / m_Cols;
}

float Sprite::GetFrameHeight() const
{
	return m_Texture.height / m_Rows;
}

