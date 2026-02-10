#include "pch.h"
#include "CObj.h"
#include "CComponent.h"

CObj::CObj()
{
}

CObj::~CObj()
{
	
}

void CObj::Initialize()
{
	for (CComponent* component : m_vecComponents)
		component->Initialize();
}

void CObj::Update()
{
	for (CComponent* component : m_vecComponents)
		component->Update();
}

void CObj::Render(HDC hDC)
{
	for (CComponent* component : m_vecComponents)
		component->Render(hDC);
}

void CObj::Release()
{
	for (CComponent* component : m_vecComponents)
	{
		component->Release();
		SAFE_DELETE(component);
	}

	m_vecComponents.clear();
		
}

void CObj::AddComponent(CComponent* component)
{
	if (component == nullptr)
		return;

	component->SetOwner(this);
	m_vecComponents.push_back(component);
}

void CObj::RemoveComponent(CComponent* component)
{
	auto it = std::remove(m_vecComponents.begin(), m_vecComponents.end(), component);
	m_vecComponents.erase(it);

	component->Release();
	SAFE_DELETE(component);
}

void CObj::OnColliderBeginOverlap(CCollider* collider, CCollider* other)
{
}

void CObj::OnColliderEndOverlap(CCollider* collider, CCollider* other)
{
}

void CObj::DestroyObject(CObj* pObj)
{
	pObj->Destroy();
}
