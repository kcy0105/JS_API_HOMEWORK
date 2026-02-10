#pragma once
#include "CCollider.h"
class CCircleCollider : public CCollider
{
public:
	CCircleCollider();
	virtual ~CCircleCollider() override;

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hDC) override;

	virtual bool CheckCollision(CCollider* other) override;

	float GetRadius() { return m_fRadius; }
	void SetRadius(float fRadius) { m_fRadius = fRadius; }


private:
	float m_fRadius = 0.f;
};

