#include "pch.h"
#include "CDevScene.h"
#include "CPlayer.h"
#include "CBoundary.h"
#include "CMonster.h"

CDevScene::CDevScene()
{
}

CDevScene::~CDevScene()
{
}

void CDevScene::Initialize()
{
	CObj::CreateObject<CBoundary>();

	pPlayer = CObj::CreateObject<CPlayer>();
	pPlayer->SetPos({ 400, 400 });

	CMonster* pMonster = CObj::CreateObject<CMonster>();
	pMonster->SetPos({ 450, 200 });
}

void CDevScene::Update()
{
	CScene::Update();
}

void CDevScene::Release()
{
	CScene::Release();
}
