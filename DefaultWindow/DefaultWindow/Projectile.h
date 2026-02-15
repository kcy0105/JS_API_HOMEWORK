#pragma once
#include "Object.h"
class Projectile : public Object
{
public:
	Projectile() {}
	virtual ~Projectile() {}

	virtual void OnInit() override;
	virtual void OnUpdate() override;
	virtual void OnRender(HDC hdc) override;
	virtual void OnRelease() override;

public:
	void SetDirection(Vec2 dir) { _dir = dir; }
	void SetOwner(Object* owner) { _owner = owner; }

public:
	virtual void OnColliderBeginOverlap(Collider* collider, Collider* other) override;

private:
	virtual void UpdatePos();

protected:
	float _radius = 10;
	Vec2 _dir = {};
	float _speed = 500;
	Object* _owner = {};

private:
	float _timeSum = 0.f;
};

