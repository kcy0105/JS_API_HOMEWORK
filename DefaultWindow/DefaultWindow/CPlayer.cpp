#include "pch.h"
#include "CPlayer.h"
#include "CTimeManager.h"
#include "CInputManager.h"
#include "CBullet.h"

CPlayer::CPlayer()
{
	SetObjectType(ObjectType::Player);
}

CPlayer::~CPlayer()
{
}

void CPlayer::Initialize()
{
	__super::Initialize();
}

void CPlayer::Update()
{
	__super::Update();

	float deltaTime = GET_SINGLE(CTimeManager)->GetDeltaTime();

	if (GET_SINGLE(CInputManager)->GetButton(KeyType::Up))
	{
		m_pos += GetDirection() * deltaTime * 200;
	}

	if (GET_SINGLE(CInputManager)->GetButtonDown(KeyType::SpaceBar))
	{
		CBullet* pBullet = CObj::CreateObject<CBullet>();
		pBullet->SetPos(m_pos);
		pBullet->SetDirection(GetDirection());
		pBullet->SetOwner(this);
	}

	float fAngleSpeed = 100;
	if (GET_SINGLE(CInputManager)->GetButton(KeyType::Left))
	{
		m_fAngle = m_fAngle + fAngleSpeed * deltaTime;
	}
	if (GET_SINGLE(CInputManager)->GetButton(KeyType::Right))
	{
		m_fAngle = m_fAngle - fAngleSpeed * deltaTime;
	}
}

void CPlayer::Render(HDC hDC)
{
	__super::Render(hDC);

	// Body
	Utils::DrawCircle(hDC, m_pos, 25);

	// Barrel
	float w = 10;
	float h1 = 50;
	float h2 = 20;

	Vec2 dir = GetDirection();

	Vec2 m1 = m_pos + h1 * dir;
	Vec2 m2 = m_pos - h2 * dir;
	Vec2 a = m1 + w / 2 * Vec2(-dir.y, dir.x);
	Vec2 b = m1 - w / 2 * Vec2(-dir.y, dir.x);
	Vec2 c = m2 + w / 2 * Vec2(-dir.y, dir.x);
	Vec2 d = m2 - w / 2 * Vec2(-dir.y, dir.x);

	Utils::DrawLine(hDC, a, b);
	Utils::DrawLine(hDC, b, d);
	Utils::DrawLine(hDC, d, c);
	Utils::DrawLine(hDC, c, a);

	Utils::DrawCircle(hDC, m_pos, 10);

}

void CPlayer::Release()
{
	__super::Release();
}
