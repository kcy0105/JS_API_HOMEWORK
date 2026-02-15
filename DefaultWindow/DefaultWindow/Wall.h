#pragma once
#include "Object.h"

class BoxCollider;

class Wall :public Object
{
public:
	Wall() {}
	virtual ~Wall() {}

	virtual void OnInit() override;
	virtual void OnUpdate() override;
	virtual void OnRender(HDC hdc) override;
	virtual void OnRelease() override;

	Vec2 GetSize() { return _size; }
	void SetSize(Vec2 size);

private:
	Vec2 _size = {};
	BoxCollider* _boxCollider = {};
};