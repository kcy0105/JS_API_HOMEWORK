#pragma once
#include "Projectile.h"
class ScrewMissile : public Projectile
{
public:
	virtual void SetPos(Pos pos) override;

private:
	virtual void UpdatePos() override;

private:
	Vec2 _linearPos = {};
	float _timeSum = 0.f;
	float _screwSize = 20.f;
	float _screwSpeed = 30.f;
};

