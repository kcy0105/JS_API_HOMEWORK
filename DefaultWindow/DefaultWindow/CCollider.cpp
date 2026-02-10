#include "pch.h"
#include "CCollider.h"
#include "CBoxCollider.h"
#include "CCircleCollider.h"
#include "CObj.h"
#include "CCollisionManager.h"

CCollider::CCollider(ColliderType colliderType) : m_colliderType(colliderType)
{
}

CCollider::~CCollider()
{
	
}

void CCollider::Initialize()
{
	GET_SINGLE(CCollisionManager)->RegisterCollider(this);
}

void CCollider::Update()
{
}

void CCollider::Render(HDC hDC)
{
}

void CCollider::Release()
{
	GET_SINGLE(CCollisionManager)->UnregisterCollider(this);
}

bool CCollider::CheckCollisionBox2Box(CBoxCollider* b1, CBoxCollider* b2)
{
	Vec2 pos1 = b1->GetOwner()->GetPos();
	Vec2 size1 = b1->GetSize();
	RECT rect1 =
	{
		(LONG)(pos1.x - size1.x / 2),
		(LONG)(pos1.y - size1.y / 2),
		(LONG)(pos1.x + size1.x / 2),
		(LONG)(pos1.y + size1.y / 2)
	};

	Vec2 pos2 = b2->GetOwner()->GetPos();
	Vec2 size2 = b2->GetSize();
	RECT rect2 =
	{
		(LONG)(pos2.x - size2.x / 2),
		(LONG)(pos2.y - size2.y / 2),
		(LONG)(pos2.x + size2.x / 2),
		(LONG)(pos2.y + size2.y / 2)
	};

	RECT rcIntersect;
	return ::IntersectRect(&rcIntersect, &rect1, &rect2);
}

bool CCollider::CheckCollisionCircle2Box(CCircleCollider* s1, CBoxCollider* b2)
{
	Vec2 cPos = s1->GetOwner()->GetPos();
	float radius = s1->GetRadius();

	Vec2 bPos = b2->GetOwner()->GetPos();
	Vec2 bSize = b2->GetSize();

	// Box의 min / max
	float left = bPos.x - bSize.x / 2;
	float right = bPos.x + bSize.x / 2;
	float top = bPos.y - bSize.y / 2;
	float bottom = bPos.y + bSize.y / 2;

	// 원 중심을 박스 내부로 clamp
	float closestX = std::max(left, std::min(cPos.x, right));
	float closestY = std::max(top, std::min(cPos.y, bottom));

	// 가장 가까운 점과 원 중심 거리
	Vec2 closestPoint(closestX, closestY);
	Vec2 dir = cPos - closestPoint;

	return dir.Length() <= radius;
}

bool CCollider::CheckCollisionCircle2Circle(CCircleCollider* s1, CCircleCollider* s2)
{
	Vec2 p1 = s1->GetOwner()->GetPos();
	float r1 = s1->GetRadius();

	Vec2 p2 = s2->GetOwner()->GetPos();
	float r2 = s2->GetRadius();

	Vec2 dir = p1 - p2;
	float dist = dir.Length();

	return dist <= r1 + r2;
}
