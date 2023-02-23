#pragma once

#include <iostream>
#include <string>
#include <cmath>

namespace lab2
{
	struct Point
	{
		double x, y;
		Point(double x0 = 0, double y0 = 0) :x(x0), y(y0) {};
	};

	class Hypocycloid
	{
		private:
			double r, d, R;

		public:
		//constructors
			Hypocycloid();
			Hypocycloid(double r_ = 1, double d = 1, double R_ = 3);

		//setters
			void setr(double r_);
			void setd(double d_);
			void setR(double R_);

		//getters
			double getr() const;
			double getd() const;
			double getR() const;

		//methods
			Point PointCoordinates(double alpha);
			double* RadiiHypocycloid();
			double CurvatureRadius(double alpha);
			double SectorialArea(double alpha);
			std::string TypeHypocycloid();
	};

	template <class T>
	int getNum(T& a)
	{
		std::cin >> a;

		while (!std::cin.good())
		{
			if (std::cin.bad())
				throw std::runtime_error("Fatal error");

			if (std::cin.eof())
				return 1;

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cout << "Invalid input. Please, try again from incorrect value" << std::endl;
			std::cin >> a;
		}

		return 0;
	};
}