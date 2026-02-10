#pragma once
#include "CScene.h"

class CPlayer;

class CGameScene : public CScene
{
public:
	CGameScene();
	virtual ~CGameScene() override;

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Release() override;

private:
	CPlayer* pPlayer = {};
};

