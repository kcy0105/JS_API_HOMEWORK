#pragma once
#include "Object.h"

class Component;
class OrbitShield;

class Player : public Object
{
public:
	Player() {}
	virtual ~Player() {}

	virtual void OnInit() override;
	virtual void OnUpdate() override;
	virtual void OnRender(HDC hdc) override;
	virtual void OnRelease() override;

private:
	float _moveSpeed = 200.f;
	float _barrelAngle = 90.f;
	float _barrelSpeed = 100.f;
	OrbitShield* _orbitShield = {};
};

