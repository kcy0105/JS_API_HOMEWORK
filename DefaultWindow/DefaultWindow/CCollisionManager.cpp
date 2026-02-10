#include "pch.h"
#include "CCollisionManager.h"
#include "CCollider.h"
#include "CObj.h"

void CCollisionManager::Initialize()
{
}

void CCollisionManager::Update()
{
	for (int32 i = 0; i < m_vecColliders.size(); i++)
	{
		for (int32 j = i + 1; j < m_vecColliders.size(); j++)
		{
			CCollider* src = m_vecColliders[i];
			CCollider* dest = m_vecColliders[j];

			if (src->CheckCollision(dest))
			{
				if (src->m_collisionMap.contains(dest) == false)
				{
					src->GetOwner()->OnColliderBeginOverlap(src, dest);
					dest->GetOwner()->OnColliderBeginOverlap(dest, src);
					src->m_collisionMap.insert(dest);
					dest->m_collisionMap.insert(src);
				}
			}
			else
			{
				if (src->m_collisionMap.contains(dest))
				{
					src->GetOwner()->OnColliderEndOverlap(src, dest);
					dest->GetOwner()->OnColliderEndOverlap(dest, src);
					src->m_collisionMap.erase(dest);
					dest->m_collisionMap.erase(src);
				}
			}
		}
	}
}

void CCollisionManager::RegisterCollider(CCollider* collider)
{
	m_vecColliders.push_back(collider);
}

void CCollisionManager::UnregisterCollider(CCollider* collider)
{
	auto it = std::remove(m_vecColliders.begin(), m_vecColliders.end(), collider);
	m_vecColliders.erase(it, m_vecColliders.end());
}
