#include "cam.h"

cam::cam(Input* in)
{
	input = in;
}

void cam::HandleInput(float dt)
{
	if (input->isKeyDown('w'))
	{
		pos.x += forward.x * dt;
		pos.y += forward.y * dt;
		pos.z += forward.z * dt;
	}
	if (input->isKeyDown('s'))
	{
		pos.x -= forward.x * dt;
		pos.y -= forward.y * dt;
		pos.z -= forward.z * dt;
	}
	if (input->isKeyDown('d'))
	{
		pos.x += right.x * dt;
		pos.y += right.y * dt;
		pos.z += right.z * dt;
	}
	if (input->isKeyDown('a'))
	{
		pos.x -= right.x * dt;
		pos.y -= right.y * dt;
		pos.z -= right.z * dt;
	}
	if (input->isKeyDown('e'))
	{
		pos.x -= up.x * dt;
		pos.y -= up.y * dt;
		pos.z -= up.z * dt;
	}
	if (input->isKeyDown('q'))
	{
		pos.x += up.x * dt;
		pos.y += up.y * dt;
		pos.z += up.z * dt;
	}
}

void cam::Update(float dt)
{
	float CosR, CosP, CosY;
	float SinR, SinP, SinY;


	CosY = cosf(yaw * 3.1415 / 180);
	CosP = cosf(pitch * 3.1415 / 180);
	CosR = cosf(roll * 3.1415 / 180);
	SinY = sinf(yaw * 3.1415 / 180);
	SinP = sinf(pitch * 3.1415 / 180);
	SinR = sinf(roll * 3.1415 / 180);

	forward.x = SinY * CosP;
	forward.y = SinP;
	forward.z = CosP * -CosY;

	right = forward.cross(up);

	lookat = pos + forward;

	up.x = -CosY * SinR - SinY * SinP * CosR;
	up.y = CosP * CosR;
	up.z = -SinY * SinR - SinP * CosR * -CosY;
}

//getters
float cam::GetPosX()
{
	return pos.x;
}
float cam::GetPosY()
{
	return pos.y;
}
float cam::GetPosZ()
{
	return pos.z;
}
float cam::GetUpX()
{
	return up.x;
}
float cam::GetUpY()
{
	return up.y;
}
float cam::GetUpZ()
{
	return up.z;
}
float cam::GetLAX()
{
	return lookat.x;
}
float cam::GetLAY()
{
	return lookat.y;
}
float cam::GetLAZ()
{
	return lookat.z;
}


void cam::SetPos(float x, float y, float z)
{
	pos.x = x;
	pos.y = y;
	pos.z = z;
}

void cam::SetRot(float y, float p, float r)
{
	yaw = y;
	pitch = p;
	roll = r;

}