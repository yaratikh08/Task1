#include"Circle1.h"

using namespace std;

Circle::Circle(double radius, double x, double y ) {
	if (radius <= 0) {
		cout << "Ошибка ввода" << endl;
		exit(1);
	}
	this->radius = radius;
	this->x = x;
	this->y = y;
}

double Circle::getLength() const {
	return 2 * M_PI * radius;
}

double Circle::getArea() const {
	return M_PI * radius * radius;
}