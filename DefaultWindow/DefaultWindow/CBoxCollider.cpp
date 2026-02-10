#include "pch.h"
#include "CBoxCollider.h"
#include "CObj.h"
#include "CCIrcleCollider.h"

CBoxCollider::CBoxCollider() : CCollider(ColliderType::Box)
{
}

CBoxCollider::~CBoxCollider()
{
}

void CBoxCollider::Initialize()
{
	__super::Initialize();
}

void CBoxCollider::Update()
{
	__super::Update();
}

void CBoxCollider::Render(HDC hDC)
{
	__super::Render(hDC);

	Vec2 pos = GetOwner()->GetPos();

	HPEN pen = CreatePen(PS_SOLID, 3, RGB(0, 255, 0));
	HPEN oldPen = (HPEN)SelectObject(hDC, pen);

	HBRUSH brush = (HBRUSH)GetStockObject(NULL_BRUSH);
	HBRUSH oldBrush = (HBRUSH)SelectObject(hDC, brush);

	Utils::DrawRect(hDC, pos, static_cast<int>(m_size.x), static_cast<int>(m_size.y));

	SelectObject(hDC, oldBrush);
	SelectObject(hDC, oldPen);

	DeleteObject(pen);
}

bool CBoxCollider::CheckCollision(CCollider* other)
{
	switch (other->GetColliderType())
	{
	case ColliderType::Box:
		return CheckCollisionBox2Box(this, static_cast<CBoxCollider*>(other));
	case ColliderType::Circle:
		return CheckCollisionCircle2Box(static_cast<CCircleCollider*>(other), this);
	}

	return false;
}
