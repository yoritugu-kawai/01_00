#pragma once

#include <cmath>
#include <Novice.h>
struct   Matrix4x4 {
	float m[4][4];
};
float Cot(float theta);

Matrix4x4 MakePerspectiveFovMatrix(float fovY, float aspectRatio, float nearClip, float farClip);

Matrix4x4 MakeOrthographicMatrix(float left, float top, float right, float bottom, float neaClip, float farClip);

Matrix4x4 MakeViewportMatrix(float left, float top, float width, float height, float minDepth, float maxDepth);

const int COLUMN_WIDTH = 60;
const int ROW_HEIGHT = 20;
void MatrixScreenPrintf(int x, int y, const Matrix4x4 matrix, const char* string);
