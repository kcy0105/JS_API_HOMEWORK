#pragma once
#include "CObj.h"

class CComponent;

class CPlayer : public CObj
{
public:
	CPlayer();
	virtual ~CPlayer() override;

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

public:
	Vec2 GetDirection() { return Vec2(::cos(m_fAngle * DEG2RAD), -::sin(m_fAngle * DEG2RAD)); }

private:
	float m_fAngle = 90;
};

