#include "pch.h"
#include "Monster.h"
#include "TimeManager.h"
#include "BoxCollider.h"
#include "CircleCollider.h"
#include "Collider.h"
#include "Player.h"

void Monster::Init()
{
	SetTag(L"Monster");
	AddComponent<BoxCollider>()->SetSize({ 50, 50 });
}

void Monster::Update()
{
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();

	if (_followPlayer)
	{
		_dir = Vec2(_player->GetPos().x - _pos.x, _player->GetPos().y - _pos.y);
		_dir.Normalize();
	}

	_pos += _dir * _speed * deltaTime;
}

void Monster::Render(HDC hdc)
{
	Utils::DrawRectInWorld(hdc, _pos, static_cast<int>(_size), static_cast<int>(_size));
}

void Monster::Release()
{
}

void Monster::OnColliderBeginOverlap(Collider* collider, Collider* other)
{
	if (_followPlayer == false)
	{
		if (other->GetOwner()->GetTag() == L"Wall")
		{
			_dir *= -1;
		}
	}
	
}

void Monster::SetFollowPlayer(bool followPlayer)
{
	if (followPlayer == false)
		_dir = { 1, 0 };

	_followPlayer = followPlayer;
}
