#include "pch.h"
#include "CBoundary.h"

CBoundary::CBoundary() : CObj(ObjectType::Boundary)
{
}

CBoundary::~CBoundary()
{
}

void CBoundary::Initialize()
{
}

void CBoundary::Update()
{
}

void CBoundary::Render(HDC hDC)
{
	Utils::DrawRect(hDC, { GWinSizeX/2, GWinSizeY/2 }, GWinSizeX - 2 * GPaddingSize, GWinSizeY - 2 * GPaddingSize);
}

void CBoundary::Release()
{
}
