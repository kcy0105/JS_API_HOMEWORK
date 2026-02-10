#pragma once
#include "CObj.h"

class CBoxCollider;

class CWall :public CObj
{
public:
	CWall();
	virtual ~CWall() override;

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

	Vec2 GetSize() { return m_size; }
	void SetSize(Vec2 size);

private:
	Vec2 m_size = {};
	CBoxCollider* m_pBoxCollider = {};
};