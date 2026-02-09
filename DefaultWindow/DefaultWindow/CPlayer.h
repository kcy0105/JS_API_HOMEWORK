#pragma once
#include "CObj.h"
class CPlayer : public CObj
{
public:
	CPlayer();
	virtual ~CPlayer() override;

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
};

