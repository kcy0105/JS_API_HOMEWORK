#pragma once
#include "CObj.h"

enum class MoveDir
{
	Left,
	Right,
};

class CMonster :public CObj
{
public:
	CMonster();
	virtual ~CMonster() override;

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

private:
	MoveDir m_moveDir = MoveDir::Right;
	float m_fSpeed = 100;
	float m_fSize = 50;
};

