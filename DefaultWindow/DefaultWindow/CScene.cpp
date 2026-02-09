#include "pch.h"
#include "CScene.h"
#include "CObj.h"

CScene::CScene()
{
}

CScene::~CScene()
{
}

void CScene::Update()
{
	UpdateObjects();
}

void CScene::Render(HDC hDC)
{
	RenderObjects(hDC);
}
void CScene::Release()
{
	for (CObj* pObj : m_pObjs)
	{
		SAFE_DELETE(pObj);
	}

	m_pObjs.clear();
}
void CScene::AddObject(CObj* pObj)
{
	m_pObjs.push_back(pObj);
}
void CScene::RemoveObject(CObj* pObj)
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
