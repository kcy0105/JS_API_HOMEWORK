#include "pch.h"
#include "Wall.h"
#include "BoxCollider.h"

void Wall::OnInit()
{
	SetTag(L"Wall");
	_boxCollider = AddComponent<BoxCollider>();
}

void Wall::OnUpdate()
{
}

void Wall::OnRender(HDC hdc)
{
	Utils::DrawRectInWorld(hdc, _pos, static_cast<int>(_size.x), static_cast<int>(_size.y));
}

void Wall::OnRelease()
{
}

void Wall::SetSize(Vec2 size)
{
	_size = size;
	if (_boxCollider)
		_boxCollider->SetSize(size);
}