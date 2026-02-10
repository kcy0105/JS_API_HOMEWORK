#pragma once
#include "CCollider.h"
class CBoxCollider : public CCollider
{
public:
	CBoxCollider();
	virtual ~CBoxCollider() override;

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hDC) override;

	virtual bool CheckCollision(CCollider* other) override;

	Vec2 GetSize() const { return m_size; }
	void SetSize(Vec2 size) { m_size = size; }

private:
	Vec2 m_size = {};
};

