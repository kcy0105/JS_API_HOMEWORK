#include "pch.h"
#include "CCircleCollider.h"
#include "CBoxCollider.h"
#include "CObj.h"

CCircleCollider::CCircleCollider() : CCollider(ColliderType::Circle)
{
}

CCircleCollider::~CCircleCollider()
{
}

void CCircleCollider::Initialize()
{
	__super::Initialize();
}

void CCircleCollider::Update()
{
	__super::Update();
}

void CCircleCollider::Render(HDC hDC)
{
	__super::Render(hDC);

	if (m_bShowDebug == false)
		return;

	Vec2 pos = GetOwner()->GetPos();

	HPEN pen = CreatePen(PS_SOLID, 3, RGB(0, 255, 0));
	HPEN oldPen = (HPEN)SelectObject(hDC, pen);

	HBRUSH brush = (HBRUSH)GetStockObject(NULL_BRUSH);
	HBRUSH oldBrush = (HBRUSH)SelectObject(hDC, brush);

	Utils::DrawCircle(hDC, pos, (int)m_fRadius);

	SelectObject(hDC, oldBrush);
	SelectObject(hDC, oldPen);

	DeleteObject(pen);
}

bool CCircleCollider::CheckCollision(CCollider* other)
{
	switch (other->GetColliderType())
	{
	case ColliderType::Box:
		return CheckCollisionCircle2Box(this, static_cast<CBoxCollider*>(other));
	case ColliderType::Circle:
		return CheckCollisionCircle2Circle(this, static_cast<CCircleCollider*>(other));
	}

	return false;
}
