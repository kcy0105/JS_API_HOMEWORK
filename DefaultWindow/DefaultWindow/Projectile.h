#pragma once
#include "Object.h"
class Projectile : public Object
{
public:
	Projectile() {}
	virtual ~Projectile() {}

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

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
};

