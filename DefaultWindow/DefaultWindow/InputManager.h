#pragma once



class InputManager
{
	DECLARE_SINGLE(InputManager);

public:
	void Initialize();
	void Update();

	bool GetButton(KeyType key) { return GetAsyncKeyState(static_cast<int>(key)) & 0x8001; }
	bool GetButtonDown(KeyType key) { return GetAsyncKeyState(static_cast<int>(key)) & 0x8000; }
	bool GetButtonUp(KeyType key) { return GetAsyncKeyState(static_cast<int>(key)) & 0x0001; }

	POINT GetMousePos() { return m_mousePos; }

private:
	POINT m_mousePos;
};

