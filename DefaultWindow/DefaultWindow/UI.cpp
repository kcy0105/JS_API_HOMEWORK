#include "pch.h"
#include "UI.h"
#include "InputManager.h"

RECT UI::GetRect()
{
	RECT rect =
	{
		(LONG)(_pos.x - _size.x / 2),
		(LONG)(_pos.y - _size.y / 2),
		(LONG)(_pos.x + _size.x / 2),
		(LONG)(_pos.y + _size.y / 2)
	};

	return rect;
}

bool UI::IsMouseInRect()
{
	RECT rect = GetRect();

	POINT mousePos = GET_SINGLE(InputManager)->GetMousePos();

	return ::PtInRect(&rect, mousePos);
}

void UI::UpdateIncludeChilds()
{
	Update();
	for (UI* child : _children)
		child->UpdateIncludeChilds();
}

void UI::RenderIncludeChilds(HDC hdc)
{
	Render(hdc);
	for (UI* child : _children)
		child->RenderIncludeChilds(hdc);
}

void UI::ReleaseIncludeChilds()
{
	Release();
	for (UI* child : _children)
	{
		child->ReleaseIncludeChilds();
		SAFE_DELETE(child);
	}

	_children.clear();
}

void UI::AddChild(UI* ui)
{
	if (ui == nullptr)
		return;

	_children.push_back(ui);
}