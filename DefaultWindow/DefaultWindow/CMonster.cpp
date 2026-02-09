#include "pch.h"
#include "CMonster.h"
#include "CTimeManager.h"

CMonster::CMonster() : CObj(ObjectType::Monster)
{
}

CMonster::~CMonster()
{
}

void CMonster::Initialize()
{
}

void CMonster::Update()
{
	float deltaTime = GET_SINGLE(CTimeManager)->GetDeltaTime();

	switch (m_moveDir)
	{
	case MoveDir::Right:
		m_pos += Vec2(1, 0) * m_fSpeed * deltaTime;
		if (m_pos.x > GWinSizeX - GPaddingSize - m_fSize/2 ) {
			m_moveDir = MoveDir::Left;
		}
		break;
	case MoveDir::Left:
		m_pos -= Vec2(1, 0) * m_fSpeed * deltaTime;
		if (m_pos.x < GPaddingSize + m_fSize/2 ) {
			m_moveDir = MoveDir::Right;
		}
		break;
	}
}

void CMonster::Render(HDC hDC)
{
	Utils::DrawRect(hDC, m_pos, static_cast<int>(m_fSize), static_cast<int>(m_fSize));
}

void CMonster::Release()
{
}
