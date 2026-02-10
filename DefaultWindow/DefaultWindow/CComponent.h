#pragma once
class CComponent
{
public:
	CComponent();
	virtual ~CComponent();

	virtual void Initialize() abstract;
	virtual void Update() abstract;
	virtual void Render(HDC hDC) abstract;
	virtual void Release() abstract;

	void SetOwner(CObj* owner) { m_owner = owner; }
	CObj* GetOwner() { return m_owner; }

protected:
	CObj* m_owner = {};
};

