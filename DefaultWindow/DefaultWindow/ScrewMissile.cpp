#include "pch.h"
#include "ScrewMissile.h"
#include "TimeManager.h"

void ScrewMissile::Init()
{
	__super::Init();
}

void ScrewMissile::Update()
{
	__super::Update();
}

void ScrewMissile::Render(HDC hdc)
{
	__super::Render(hdc);
}

void ScrewMissile::Release()
{
	__super::Release();
}

void ScrewMissile::SetPos(Pos pos)
{
	__super::SetPos(pos);
	_linearPos = pos;
}

void ScrewMissile::UpdatePos()
{
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();
	_linearPos += _speed * _dir * deltaTime;
	_timeSum += deltaTime;

	Vec2 normalVec = { _dir.y, -_dir.x };
	_pos = _linearPos + _screwSize * normalVec * ::sin(_timeSum * _screwSpeed);
}
