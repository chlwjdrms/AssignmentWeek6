#include <iostream>
#include <string>
#include <vector>

#include <GLFW/glfw3.h>
#include <cstring>
#include <stdlib.h>		  // srand, rand
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include "math.h"

#include "DrawInCircle.h"
#include "DrawInRect.h"

using namespace std;

// problem 1
template <class T_type>
void print(const T_type& i) {
	cout << i << endl;
}

// problem 2
template <class T_type>
class VectorType2D {
	T_type x_, y_;
};

// problem 3
template<class T_HOW_TO_DRAW>
class GeometricObjectInColor : public GeometricObjectInterface {
public:
	void draw() {
		T_HOW_TO_DRAW draw_in_color;
		draw_in_color.draw();
	}
};

void drawOnPixelBuffer(double xpos, double ypos) {
	std::fill_n(pixels, width*height * 3, 1.0f);

	// problem 3 Test
	vector<GeometricObjectInterface*> obj_list;

	obj_list.push_back(new GeometricObjectInColor<DrawInCircle<int>>);
	obj_list.push_back(new GeometricObjectInColor<DrawInRect<int>>);

	for (auto itr : obj_list)
		itr->draw();
}
int main() {
	// problem 1 Test
	cout << "------- Problem1 -------" << endl;
	print(1);
	print(2.345f);
	print("hellow world");

	// OpenGL
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	glClearColor(1, 1, 1, 1); // while background

	//»ï°¢Çü ÁÂÇ¥
	float vertices[] =
	{
		0.0, 0.5, 0.0, //top corner
		-0.5, -0.5, 0.0, //bottom left corner
		0.5, -0.5, 0.0 //bottom right corner
	};


	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		double xpos, ypos;

		glfwGetCursorPos(window, &xpos, &ypos);


		/* Render here */
		//glClear(GL_COLOR_BUFFER_BIT);

		drawOnPixelBuffer(xpos, ypos);


		//TODO: RGB struct
		//Make a pixel drawing function
		//Make a line drawing function

		glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	glfwTerminate();

	delete[] pixels; // or you may reuse pixels array 

	return 0;
}