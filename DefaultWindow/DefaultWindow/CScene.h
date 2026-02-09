#pragma once
class CObj;

class CScene
{
public:
	CScene();
	virtual ~CScene();

	virtual void Initialize() abstract;
	virtual void Update();
	void Render(HDC hDC);
	virtual void Release();

	void AddObject(CObj* pObj);
	void RemoveObject(CObj* pObj);

	void RenderObjects(HDC hDC);
	void UpdateObjects();

private:
	vector<int> m_ints;
	vector<CObj*> m_pObjs;
};

