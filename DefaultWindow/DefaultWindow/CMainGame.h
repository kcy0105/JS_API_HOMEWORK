#pragma once
class CMainGame
{
public:
	CMainGame();
	~CMainGame();

public:
	void Initialize();
	void Update();
	void Render();
	void Release();

private:
	HDC m_hDC = {};

private:
	// Double Buffering
	RECT m_rect = {};
	HDC m_hDCBack = {};
	HBITMAP m_bmpBack = {};
};

