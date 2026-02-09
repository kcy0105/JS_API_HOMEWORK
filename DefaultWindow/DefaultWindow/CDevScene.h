#pragma once
#include "CScene.h"

class CPlayer;

class CDevScene : public CScene
{
public:
	CDevScene();
	virtual ~CDevScene() override;

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Release() override;

private:
	CPlayer* pPlayer = {};
};

