#pragma once

/*
Datatypes H:

Information for all internal data types, universal constants, (and possibly basic functions)

All Unions/structs are set up to start with zero-values.

*/

#define PI 3.14159f
#define _2PI 6.28318f
#define PIHALF 1.570795f
#define EPSILON 0.001f
#ifndef NULL
#define NULL 0
#endif
#define MAX_PATH 260

typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;
typedef uint color;

union vector3 {
	float e[3];

	struct {
		float x,y,z;
	};

	vector3();
	vector3(float _x, float _y, float _z);

	vector3 operator+(const vector3&) const;
	vector3 operator-(const vector3&) const;
	const vector3& operator+=(const vector3&);
	const vector3& operator-=(const vector3&);

	vector3 operator*(const float&) const;
	const vector3& operator*=(const float&);

	//Dot Product
	float operator*(const vector3&) const;

	float dot2D(const vector3&) const;
	void normalize();
	float length() const;
};

union quaternion {
	float e[4];

	struct {
		float q,x,y,z;
	};

	quaternion();
};

union matrix {
	float e[16];

	float m[4][4];

	matrix();
	matrix(const matrix&);

	const matrix& operator*=(const matrix&);
	const matrix& operator+=(const matrix&);
	const matrix& operator-=(const matrix&);
	matrix operator*(const matrix&);
	matrix operator+(const matrix&);
	matrix operator-(const matrix&);
};

struct rect
{
	long left, top, right, bottom;
};

struct pt
{
	int x,y;

	pt(int _x = 0, int _y = 0) : x(_x), y(_y) {}
};

struct textureData
{
	char filename[MAX_PATH];
	int ref;			//Ref count, how many things are using it
	void* texture;		//Texture pointer type varies depending on renderer
	int width;
	int height;

	textureData();
};