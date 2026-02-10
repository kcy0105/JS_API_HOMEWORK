#pragma once
class CObj;

class CScene
{
public:
	CScene();
	virtual ~CScene();

	virtual void Initialize();
	virtual void Update();
	void Render(HDC hDC);
	virtual void Release();

	void RegisterObject(CObj* pObj);
	void UnregisterObject(CObj* pObj);

	void RenderObjects(HDC hDC);
	void UpdateObjects();
	void RemoveDeadObjects();

private:
	vector<int> m_ints;
	vector<CObj*> m_pObjs;
};

