#pragma once

class CScene;

class CSceneManager
{
	DECLARE_SINGLE(CSceneManager)

public:
	void Initialize();
	void Update();
	void Render(HDC hDC);

	void Clear();

public:
	void ChangeScene(SceneType sceneType);
	CScene* GetScene() { return m_Scene; }

private:
	class CScene* m_Scene = nullptr;
	SceneType m_sceneType = SceneType::None;
};

