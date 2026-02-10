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
	void SetOwner(CObj* owner) { m_owner = owner; }

public:
	virtual void OnColliderBeginOverlap(CCollider* collider, CCollider* other) override;
	virtual void OnColliderEndOverlap(CCollider* collider, CCollider* other) override;

private:
	float m_fRadius = 10;
	Vec2 m_dir = {};
	float m_fSpeed = 500;
	CObj* m_owner = {};
};

