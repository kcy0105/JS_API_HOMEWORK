#pragma once
#include "Object.h"
class OrbitShield : public Object
{
public:
	OrbitShield() {}
	virtual ~OrbitShield() {}

public:
	virtual void OnInit();
	virtual void OnUpdate();
	virtual void OnRender(HDC hdc);
	virtual void OnRelease();

	virtual void OnColliderBeginOverlap(Collider* collider, Collider* other) override;

public:
	void SetOwner(Object* owner) { _owner = owner; }

private:
	Object* _owner = {};
	float _angle = 0.f;
	float _radius = 15.f;
	float _orbitRadius = 50.f;
	float _speed = 100.f;
};

