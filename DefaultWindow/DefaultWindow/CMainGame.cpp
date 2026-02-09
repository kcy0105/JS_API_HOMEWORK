#include "pch.h"
#include "CMainGame.h"
#include "CTimeManager.h"
#include "CSceneManager.h"
#include "CInputManager.h"

CMainGame::CMainGame()
{
}

CMainGame::~CMainGame()
{
	_CrtDumpMemoryLeaks();
	Release();
}

void CMainGame::Initialize()
{
	m_hDC = GetDC(g_hWnd);

	::GetClientRect(g_hWnd, &m_rect);

	m_hDCBack = ::CreateCompatibleDC(m_hDC);
	m_bmpBack = ::CreateCompatibleBitmap(m_hDC, m_rect.right, m_rect.bottom);
	HBITMAP prev = (HBITMAP)::SelectObject(m_hDCBack, m_bmpBack);
	::DeleteObject(prev);

	GET_SINGLE(CTimeManager)->Initialize();
	GET_SINGLE(CInputManager)->Initialize();
	GET_SINGLE(CSceneManager)->Initialize();

	GET_SINGLE(CSceneManager)->ChangeScene(SceneType::DevScene);
}

void CMainGame::Update()
{
	GET_SINGLE(CTimeManager)->Update();
	GET_SINGLE(CInputManager)->Update();
	GET_SINGLE(CSceneManager)->Update();
}

void CMainGame::Render()
{
	GET_SINGLE(CSceneManager)->Render(m_hDCBack);

	uint32 fps = GET_SINGLE(CTimeManager)->GetFps();
	float deltaTime = GET_SINGLE(CTimeManager)->GetDeltaTime();

	{
		POINT mousePos = GET_SINGLE(CInputManager)->GetMousePos();
		wstring str = std::format(L"Mouse({0}, {1})", mousePos.x, mousePos.y);
		::TextOut(m_hDCBack, 20, 10, str.c_str(), static_cast<int32>(str.size()));
	}

	{
		wstring str = std::format(L"FPS({0}), DT({1})", fps, deltaTime);
		::TextOut(m_hDCBack, 550, 10, str.c_str(), static_cast<int32>(str.size()));
	}

	// Double Buffering
	::BitBlt(m_hDC, 0, 0, m_rect.right, m_rect.bottom, m_hDCBack, 0, 0, SRCCOPY); // 비트 블릿 : 고속 복사
	::PatBlt(m_hDCBack, 0, 0, m_rect.right, m_rect.bottom, WHITENESS);
}

void CMainGame::Release()
{
}
