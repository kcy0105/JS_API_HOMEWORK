#include "pch.h"
#include "CBullet.h"
#include "CTimeManager.h"

CBullet::CBullet() : CObj(ObjectType::Bullet)
{
}

CBullet::~CBullet()
{
}

void CBullet::Initialize()
{
}

void CBullet::Update()
{
	float deltaTime = GET_SINGLE(CTimeManager)->GetDeltaTime();

	m_pos += m_fSpeed * m_dir * deltaTime;

	if (m_pos.x < GPaddingSize
		|| m_pos.x > GWinSizeX - GPaddingSize
		|| m_pos.y < GPaddingSize
		|| m_pos.y > GWinSizeY - GPaddingSize)
	{
		Destroy();
	}
}

void CBullet::Render(HDC hDC)
{
	Utils::DrawCircle(hDC, m_pos, static_cast<int32>(m_fRadius));
}

void CBullet::Release()
{
}
