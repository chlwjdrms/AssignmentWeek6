#include <iostream>
#include <string>
#include <vector>

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
class DrawInYellow {
public:
	void draw() {
		cout << "Draw in Yellow" << endl;
	}
};
class DrawInRed {
public:
	void draw() {
		cout << "Draw in Red" << endl;
	}
};

class GeometricObjectInterface {
public:
	virtual void draw() = 0;

};

template<class T_HOW_TO_DRAW>
class GeometricObjectInColor : public GeometricObjectInterface {
public:
	void draw() {
		T_HOW_TO_DRAW draw_in_color;
		draw_in_color.draw();
	}
};
int main() {
	// problem 1 Test
	cout << "------- Problem1 -------" << endl;
	print(1);
	print(2.345f);
	print("hellow world");

	cout << "------- Problem3 -------" << endl;
	// problem 3 Test
	vector<GeometricObjectInterface*> obj_list;

	obj_list.push_back(new GeometricObjectInColor<DrawInYellow>);
	obj_list.push_back(new GeometricObjectInColor<DrawInRed>);

	for (auto itr : obj_list)
		itr->draw();

	return 0;
}