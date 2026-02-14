#pragma once
#include "SceneManager.h"
#include "Scene.h"

class Component;
class Collider;

class Object
{
public:
	Object() {};
	virtual ~Object() {};

public:
	virtual void Init() {} // Object를 상속받은 클래스의 자식 클래스에서 첫번째에 __super.Init() 사용
	virtual void Update() {}
	virtual void LateUpdate() {} // 필요할 때만 override
	virtual void Render(HDC hdc) {}
	virtual void Release() {} // Object를 상속받은 클래스의 자식 클래스에서 마지막에 __super.Init() 사용

public: // Scene에서 호출
	// Init은 컴포넌트 추가 시 실행된다.
	virtual void UpdateIncludeComponents();
	virtual void LateUpdateIncludeComponents();
	virtual void RenderIncludeComponents(HDC hdc);
	virtual void ReleaseIncludeComponents();
	
public: // 충돌 처리 필요 시 override
	virtual void OnColliderBeginOverlap(Collider* collider, Collider* other) {}
	virtual void OnColliderEndOverlap(Collider* collider, Collider* other) {}

public:
	Pos GetPos() { return _pos; }
	virtual void SetPos(Pos pos) { _pos = pos; }
	wstring GetTag() { return _tag; }
	void SetTag(wstring tag) { _tag = tag; }

protected:
	Pos _pos = {};
	wstring _tag = {};

public:
	template<typename T>
	T* AddComponent()
	{
		static_assert(std::is_convertible_v<T*, Component*>);

		T* component = new T();
		component->SetOwner(this);
		_components.push_back(component);
		component->Init();

		return component;
	}
	void RemoveComponent(Component* component);

protected:
	vector<Component*> _components;

public:
	template<typename T>
	static T* CreateObject()
	{
		static_assert(std::is_convertible_v<T*, Object*>);

		T* obj = new T();
		obj->Init();

		GET_SINGLE(SceneManager)->GetScene()->RegisterObject(obj);

		return obj;
	}
	static void DestroyObject(Object* obj) { obj->Destroy(); }

protected:
	void Destroy() { _isDead = true; }

public:
	bool IsDead() { return _isDead; }

private:
	bool _isDead = false;
};

