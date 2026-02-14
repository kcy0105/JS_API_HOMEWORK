#include "pch.h"
#include "Camera.h"
#include "CameraComponent.h"
#include "Player.h"

void Camera::Init()
{
	AddComponent<CameraComponent>();
}

void Camera::Update()
{
}

void Camera::LateUpdate()
{
	_pos = _player->GetPos();
}

void Camera::Render(HDC hdc)
{
}

void Camera::Release()
{
}
