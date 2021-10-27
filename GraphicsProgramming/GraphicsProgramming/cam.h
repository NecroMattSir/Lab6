#pragma once


#include "Input.h"
#include "Vector3.h"

class cam
{
public:
	cam(Input* in);

	void HandleInput(float dt);
	void Update(float dt);


	float GetPosX();
	float GetPosY();
	float GetPosZ();
	float GetLAX();
	float GetLAY();
	float GetLAZ();
	float GetUpX();
	float GetUpY();
	float GetUpZ();


	void SetPos(float x, float y, float z);
	void SetRot(float y, float p, float r);


protected:
	Vector3 pos;
	Vector3 forward;
	Vector3 lookat;
	Vector3 up;
	Vector3 right;
	float pitch;
	float yaw;
	float roll;

	Input* input;
};

