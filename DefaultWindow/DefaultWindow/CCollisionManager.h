#pragma once

class CCollider;

class CCollisionManager
{
	DECLARE_SINGLE(CCollisionManager)

public:
	void Initialize();
	void Update();

	void RegisterCollider(CCollider* collider);
	void UnregisterCollider(CCollider* collider);

private:
	vector<CCollider*> m_vecColliders;
};

