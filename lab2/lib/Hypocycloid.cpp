#include "Hypocycloid.hpp"

using namespace std;

namespace lab2
{
	// constructors
	Hypocycloid::Hypocycloid() : r(1), d(1), R(2) { }

	Hypocycloid::Hypocycloid(double r_, double d_, double R_)
	{
		if (r_ < 0)
			throw exception("constructor error...");

		if (d_ < 0)
			throw exception("constructor error...");

		if (R_ < 0)
			throw exception("constructor error...");

		r = r_;
		d = d_;
		R = R_;
	}

	//setters
	void Hypocycloid::setr(double r_)
	{
		if (r_ < 0)
			throw exception("constructor error...");

		r = r_;
	}

	void Hypocycloid::setd(double d_)
	{
		if (d_ < 0)
			throw exception("constructor error...");

		d = d_;
	}

	void Hypocycloid::setR(double R_)
	{
		if (R_ < 0)
			throw exception("constructor error...");

		R = R_;
	}

	//getters
	double Hypocycloid::getr() const { return r; }
	double Hypocycloid::getd() const { return d; }
	double Hypocycloid::getR() const { return R; }

	//methods
	Point Hypocycloid::PointCoordinates(double alpha)
	{
		double x, y;

		x = ((R - r) * cos(alpha)) + (d * (cos(((R - r) / r) * alpha)));
		y = ((R - r) * sin(alpha)) - (d * (sin(((R - r) / r) * alpha)));

		return Point(x, y);
	}

	double* Hypocycloid::RadiiHypocycloid()
	{
		double* radiuses;
		try
		{
			radiuses = new double[3];
		}
		catch (bad_alloc& ba)
		{
			throw (ba);

			return nullptr;
		}
		radiuses[0] = r;
		radiuses[1] = d;
		radiuses[2] = R;

		return radiuses;
	}

	double Hypocycloid::CurvatureRadius(double alpha)
	{
		double CurvR;
		
		CurvR = ((4 * r) * fabs(R - r)) / (fabs(R - (2 * r)) * (sin((R * alpha) / (2 * r))));

		return CurvR;
	}

	double Hypocycloid::SectorialArea(double alpha)
	{
		double SectA;

		SectA = ((R - r) / 2) * (((R - r - ((d * d) / r)) * alpha) + (((d * (R - 2 * r)) / R) * sin((R * alpha) / r)));

		return SectA;
	}

	string Hypocycloid::TypeHypocycloid()
	{
;		if (d > r)
			return "Hypocycloid Elonged";
		if (d < r)
			return "Hypocycloid Shorted";

		return "Hypocycloid Ordinary";
	}
};