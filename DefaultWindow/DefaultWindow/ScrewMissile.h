#pragma once
#include "Projectile.h"
class ScrewMissile : public Projectile
{
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	virtual void SetPos(Pos pos) override;

private:
	virtual void UpdatePos() override;

private:
	Vec2 _linearPos = {};
	float _timeSum = 0.f;
	float _screwSize = 20.f;
	float _screwSpeed = 30.f;
};

