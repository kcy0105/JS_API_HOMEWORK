#pragma once
#include "CObj.h"
class CBoundary :public CObj
{
public:
	CBoundary();
	virtual ~CBoundary() override;

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
};