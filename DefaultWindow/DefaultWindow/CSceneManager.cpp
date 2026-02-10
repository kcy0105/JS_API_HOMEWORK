#include "pch.h"
#include "CSceneManager.h"
#include "CScene.h"
#include "CGameScene.h"

void CSceneManager::Initialize()
{
}

void CSceneManager::Update()
{
	if (m_Scene)
		m_Scene->Update();
}

void CSceneManager::Render(HDC hDC)
{
	if (m_Scene)
		m_Scene->Render(hDC);
}

void CSceneManager::Clear()
{
	if (m_Scene)
	{
		m_Scene->Release();
		SAFE_DELETE(m_Scene);
	}
}

void CSceneManager::ChangeScene(SceneType sceneType)
{
	if (m_sceneType == sceneType)
		return;

	CScene* newScene = nullptr;

	switch (sceneType)
	{
	case SceneType::GameScene:
		newScene = new CGameScene();
	}

	if (m_Scene)
	{
		m_Scene->Release();
		SAFE_DELETE(m_Scene);
	}	

	m_Scene = newScene;
	m_sceneType = sceneType;

	newScene->Initialize();
}
