#pragma once
#include "Object.h"

class Player;

class Monster :public Object
{
public:
	Monster() {}
	virtual ~Monster() {}

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

public:
	virtual void OnColliderBeginOverlap(Collider* collider, Collider* other) override;

public:
	void SetPlayer(Player* player) { _player = player; }
	void SetFollowPlayer(bool followPlayer);

private:
	Vec2 _dir = { 1, 0 };
	float _speed = 100;
	float _size = 50;

	bool _followPlayer = false;
	Player* _player = {};
};

