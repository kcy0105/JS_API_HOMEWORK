#pragma once
class CObj
{
public:
	CObj(ObjectType type);
	virtual ~CObj();

public:
	virtual void Initialize() abstract;
	virtual void Update() abstract;
	virtual void Render(HDC hDC) abstract;
	virtual void Release() abstract;

public:
	ObjectType GetObjectType() const { return m_type; }

	Pos GetPos() const { return m_pos; }
	void SetPos(Pos pos) { m_pos = pos; }

protected:
	ObjectType m_type = ObjectType::None;
	Pos m_pos = {};

public:
	template<typename T>
	static T* CreateObject()
	{
		static_assert(std::is_convertible_v<T*, CObj*>);

		T* pObj = new T();
		pObj->Initialize();

		GET_SINGLE(CSceneManager)->GetScene()->AddObject(pObj);

		return pObj;
	}
	static void DestroyObject(CObj* pObj);

protected:
	void Destroy() { DestroyObject(this); }
};

