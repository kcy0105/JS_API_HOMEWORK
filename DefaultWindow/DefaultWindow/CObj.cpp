#include "pch.h"
#include "CObj.h"

CObj::CObj(ObjectType type) : m_type(type)
{
}

CObj::~CObj()
{
}

void CObj::DestroyObject(CObj* pObj)
{
	if (pObj == nullptr)
		return;

	GET_SINGLE(CSceneManager)->GetScene()->RemoveObject(pObj);

	pObj->Release();
	SAFE_DELETE(pObj);
}
