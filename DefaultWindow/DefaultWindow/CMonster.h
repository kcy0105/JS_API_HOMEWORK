#pragma once
#include "CObj.h"


class CMonster :public CObj
{
public:
	CMonster();
	virtual ~CMonster() override;

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

public:
	virtual void OnColliderBeginOverlap(CCollider* collider, CCollider* other) override;
	virtual void OnColliderEndOverlap(CCollider* collider, CCollider* other) override;

private:
	Vec2 m_dir = { 1, 0 };
	float m_fSpeed = 100;
	float m_fSize = 50;
};

