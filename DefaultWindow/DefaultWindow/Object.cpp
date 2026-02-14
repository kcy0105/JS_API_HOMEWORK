#include "pch.h"
#include "Object.h"
#include "Component.h"

void Object::UpdateIncludeComponents()
{
	Update();
	for (Component* component : _components)
		component->Update();
}

void Object::LateUpdateIncludeComponents()
{
	LateUpdate();
	for (Component* component : _components)
		component->LateUpdate();
}

void Object::RenderIncludeComponents(HDC hdc)
{
	Render(hdc);
	for (Component* component : _components)
		component->Render(hdc);
}

void Object::ReleaseIncludeComponents()
{
	Release();
	for (Component* component : _components)
	{
		component->Release();
		SAFE_DELETE(component);
	}

	_components.clear();
}

void Object::RemoveComponent(Component* component)
{
	auto it = std::remove(_components.begin(), _components.end(), component);
	_components.erase(it);

	component->Release();
	SAFE_DELETE(component);
}