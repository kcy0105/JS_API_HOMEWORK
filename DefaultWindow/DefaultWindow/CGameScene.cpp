#include "pch.h"
#include "CGameScene.h"
#include "CPlayer.h"
#include "CWall.h"
#include "CMonster.h"

CGameScene::CGameScene()
{
}

CGameScene::~CGameScene()
{
}

void CGameScene::Initialize()
{
	__super::Initialize();

	{
		CWall* pWall = CObj::CreateObject<CWall>();
		pWall->SetPos({ 300, 50 });
		pWall->SetSize({ 800, 100 });
	}

	{
		CWall* pWall = CObj::CreateObject<CWall>();
		pWall->SetPos({ 50, 300 });
		pWall->SetSize({ 100, 600 });
	}

	{
		CWall* pWall = CObj::CreateObject<CWall>();
		pWall->SetPos({ 750, 300 });
		pWall->SetSize({ 100, 600 });
	}
	


	pPlayer = CObj::CreateObject<CPlayer>();
	pPlayer->SetPos({ 400, 450 });

	CMonster* pMonster = CObj::CreateObject<CMonster>();
	pMonster->SetPos({ 450, 200 });
}

void CGameScene::Update()
{
	__super::Update();
}

void CGameScene::Release()
{
	__super::Release();
}
