#include "pch.h"
#include "CPlayer.h"
#include "CTimeManager.h"
#include "CInputManager.h"
#include "CBullet.h"

CPlayer::CPlayer() : CObj(ObjectType::Player)
{
}

CPlayer::~CPlayer()
{
}

void CPlayer::Initialize()
{
}

void CPlayer::Update()
{
	float deltaTime = GET_SINGLE(CTimeManager)->GetDeltaTime();

#pragma region 이동
	Vec2 moveDir = { 0, 0 };
	
	if (GET_SINGLE(CInputManager)->GetButton(KeyType::Left))
	{
		moveDir += Vec2(-1, 0);
	}
	if (GET_SINGLE(CInputManager)->GetButton(KeyType::Right))
	{
		moveDir += Vec2(1, 0);
	}
	if (GET_SINGLE(CInputManager)->GetButton(KeyType::Up))
	{
		moveDir += Vec2(0, -1);
	}
	if (GET_SINGLE(CInputManager)->GetButton(KeyType::Down))
	{
		moveDir += Vec2(0, 1);
	}

	moveDir.Normalize();

	m_pos += moveDir * deltaTime * 200;
#pragma endregion

#pragma region 총알 발사
	if (GET_SINGLE(CInputManager)->GetButtonDown(KeyType::W))
	{
		CBullet* pBullet = CObj::CreateObject<CBullet>();
		pBullet->SetPos(m_pos);
		pBullet->SetDirection(Vec2(0, -1));
	}
	else if (GET_SINGLE(CInputManager)->GetButtonDown(KeyType::A))
	{
		CBullet* pBullet = CObj::CreateObject<CBullet>();
		pBullet->SetPos(m_pos);
		pBullet->SetDirection(Vec2(-1, 0));
	}
	else if (GET_SINGLE(CInputManager)->GetButtonDown(KeyType::S))
	{
		CBullet* pBullet = CObj::CreateObject<CBullet>();
		pBullet->SetPos(m_pos);
		pBullet->SetDirection(Vec2(0, 1));
	}
	else if (GET_SINGLE(CInputManager)->GetButtonDown(KeyType::D))
	{
		CBullet* pBullet = CObj::CreateObject<CBullet>();
		pBullet->SetPos(m_pos);
		pBullet->SetDirection(Vec2(1, 0));
	}
#pragma endregion
}

void CPlayer::Render(HDC hDC)
{
	Utils::DrawCircle(hDC, m_pos, 25);
}

void CPlayer::Release()
{
}
