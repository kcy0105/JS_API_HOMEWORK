#pragma once
#include <string>
#include "CSceneManager.h"
#include "CScene.h"
using namespace std;

class CObj;

class Utils
{
public: // Draw
	static void DrawText(HDC hDC, Pos pos, const wstring& str);
	static void DrawRect(HDC hDC, Pos pos, int32 w, int32 h);
	static void DrawCircle(HDC hDC, Pos pos, int32 radius);
	static void DrawLine(HDC hDC, Pos from, Pos to);
};

