#include "pch.h"
#include "CScene.h"
#include "CObj.h"
#include "CCollisionManager.h"

CScene::CScene()
{
}

CScene::~CScene()
{
}

void CScene::Initialize()
{
}

void CScene::Update()
{
	UpdateObjects();

	GET_SINGLE(CCollisionManager)->Update();

	RemoveDeadObjects();
}

void CScene::Render(HDC hDC)
{
	RenderObjects(hDC);
}

void CScene::Release()
{
	for (CObj* pObj : m_pObjs)
	{
		pObj->Release();
		SAFE_DELETE(pObj);
	}
	m_pObjs.clear();
}

void CScene::RegisterObject(CObj* pObj)
{
	m_pObjs.push_back(pObj);
}

void CScene::UnregisterObject(CObj* pObj)
{
	if (pObj == nullptr)
		return;

	auto it = std::remove(m_pObjs.begin(), m_pObjs.end(), pObj);
	m_pObjs.erase(it, m_pObjs.end());
}


void CScene::RenderObjects(HDC hDC)
{
	for (CObj* pObj : m_pObjs)
	{
		pObj->Render(hDC);
	}
}

void CScene::UpdateObjects()
{
	const vector<CObj*> pObjs = m_pObjs;
	for (CObj* pObj : pObjs)
	{
		pObj->Update();
	}
}

void CScene::RemoveDeadObjects()
{
	const vector<CObj*> pObjs = m_pObjs;
	for (CObj* pObj : pObjs)
	{
		if (pObj->IsDead())
		{
			UnregisterObject(pObj);
			pObj->Release();
			SAFE_DELETE(pObj);
		}
	}
}
