#pragma once

const int width = 1500;
const int height = 480;


float* pixels = new float[width*height * 3];

template<class T_Type>
void drawPixel(const T_Type& i, const T_Type& j, const float& red, const float& green, const float& blue)
{
	pixels[(i + width* j) * 3 + 0] = red;
	pixels[(i + width* j) * 3 + 1] = green;
	pixels[(i + width* j) * 3 + 2] = blue;
}
template<class T_Type>
void drawLine(const T_Type& i0, const T_Type& j0, const T_Type& i1, const T_Type& j1, const float& red, const float& green, const float& blue)
{
	for (T_Type i = i0; i <= i1; i++)
	{
		const T_Type j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;

		drawPixel(i, j, red, green, blue);
	}
}
template<class T_Type>
void drawCircle(const T_Type& i4, const T_Type& j4, const T_Type& i5, const T_Type& j5, const float& red, const float& green, const float& blue) {
	for (T_Type i = i4; i <= i5; i++) {
		for (T_Type j = j4; j <= j5; j++) {
			T_Type r = (i5 - i4) / 2;
			T_Type a = (i - (i4 + i5) / 2)*(i - (i4 + i5) / 2) + (j - (j4 + j5) / 2)*(j - (j4 + j5) / 2);
			if (a <= r*r && a >= (r - 3)*(r - 3)) {
				drawPixel(i, j, red, green, blue);
			}
		}
	}
}
