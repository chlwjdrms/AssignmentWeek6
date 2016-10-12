#pragma once

#include "drawSub.h"
#include "GeometricObjectInterface.h"

template<class T_Type>
class DrawInCircle {
public:
	T_Type start_x, start_y;
	T_Type end_x, end_y;
	double xpos, ypos;
public:
	DrawInCircle() {}

	DrawInCircle(const T_Type& _start_x, const T_Type& _start_y, const T_Type& _end_x, const T_Type& _end_y, double _xpos, double _ypos) {
		initialize(_start_x, _start_y, _end_x, _end_y, _xpos, _ypos);
	}
	void initialize(const T_Type& _start_x, const T_Type& _start_y, const T_Type& _end_x, const T_Type& _end_y, double _xpos, double _ypos) {
		start_x = _start_x;
		start_y = _start_y;
		end_x = _end_x;
		end_y = _end_y;
		xpos = _xpos;
		ypos = _ypos;
	}
	void draw() {
		initialize(50, 300, 200, 450, xpos, ypos);
		drawCircleInCircle(start_x, start_y, end_x, end_y, 1.0f, 0.0f, 0.0f, xpos, ypos);
	}

	void drawCircleInCircle(const T_Type& i4, const T_Type& j4, const T_Type& i5, const T_Type& j5, const float& red, const float& green, const float& blue, double xpos, double ypos) {

		T_Type k1 = i4 + (i5 - i4) / 4;
		T_Type k2 = i5 - (i5 - i4) / 4;
		T_Type l1 = j4 + (j5 - j4) / 4;
		T_Type l2 = j5 - (j5 - j4) / 4;

		for (T_Type i = k1; i <= k2; i++) {
			for (T_Type j = l1; j <= l2; j++) {
				T_Type r = (k2 - k1) / 2;
				T_Type a = (i - (k1 + k2) / 2)*(i - (k1 + k2) / 2) + (j - (l1 + l2) / 2)*(j - (l1 + l2) / 2);
				if (a <= r*r && a >= (r - 8)*(r - 8)) {
					drawPixel(i, j, red, green, blue);
				}
			}
		}
	}
};