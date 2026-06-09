#pragma once
#define _USE_MATH_DEFINES
#include<cmath>
#include<iostream>

/**
	@brief   класс окружность
**/
class Circle {
private:
	// @brief радиус
	double radius;
	double x;
	double y;
public:
	/**
		@brief конструктор
		@param radius - радиус
	**/
	Circle(const double x = 0.0, const double y = 0.0, const double r = 1.0);

	/**
		@brief рассчет длины
		@return рассчитанное значение
	**/
	double getLength() const;

	/**
		@brief  рассчет площади
		@return рассчитанное значение
	**/
	double getArea() const;

};