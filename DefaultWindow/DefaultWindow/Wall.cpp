#include "pch.h"
#include "Wall.h"
#include "BoxCollider.h"

void Wall::Init()
{
	SetTag(L"Wall");
	_boxCollider = AddComponent<BoxCollider>();
}

void Wall::Update()
{
}

void Wall::Render(HDC hdc)
{
	Utils::DrawRectInWorld(hdc, _pos, static_cast<int>(_size.x), static_cast<int>(_size.y));
}

void Wall::Release()
{
}

void Wall::SetSize(Vec2 size)
{
	_size = size;
	if (_boxCollider)
		_boxCollider->SetSize(size);
}