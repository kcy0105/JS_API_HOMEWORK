#pragma once
#include "CComponent.h"

class CBoxCollider;
class CCircleCollider;

class CCollider : public CComponent
{
public:
	CCollider(ColliderType colliderType);
	virtual ~CCollider() override;

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

	virtual bool CheckCollision(CCollider* other) = 0;
	
	ColliderType GetColliderType() { return m_colliderType; }
	void SetShowDebug(bool bShowDebug) { m_bShowDebug = bShowDebug; }

public:
	static bool CheckCollisionBox2Box(CBoxCollider* b1, CBoxCollider* b2);
	static bool CheckCollisionCircle2Box(CCircleCollider* s1, CBoxCollider* b2);
	static bool CheckCollisionCircle2Circle(CCircleCollider* s1, CCircleCollider* s2);
protected:
	ColliderType m_colliderType = {};
	bool m_bShowDebug = true;

public:
	unordered_set<CCollider*> m_collisionMap;
};

