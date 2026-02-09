#pragma once
#include "CObj.h"

class CBullet : public CObj
{
public:
	CBullet();
	virtual ~CBullet() override;

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

public:
	void SetDirection(Vec2 dir) { m_dir = dir; }

private:
	float m_fRadius = 10;
	Vec2 m_dir = {};
	float m_fSpeed = 300;
};

