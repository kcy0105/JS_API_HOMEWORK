#pragma once
#include "Projectile.h"

class Bullet : public Projectile
{
public:
	Bullet() {}
	virtual ~Bullet() {}

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;
};

