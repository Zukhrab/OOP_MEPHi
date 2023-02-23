#include "../Lab2Lib/Hypocycloid.hpp"

using namespace std;
using namespace lab2;

void menu()
{
	cout << "1. Return the coordinates of the point" << endl;
	cout << "2. Return the radii of the circles" << endl;
	cout << "3. Return the radius of curvature" << endl;
	cout << "4. Return the hypocycloid type" << endl;
	cout << "5. Return the sectorial area" << endl;
	cout << "Make your choice --> ";
}

int main()
{
	Hypocycloid Hypo(1, 1, 3);
	
	int choose;
	double phi;

	menu();
	getNum(choose);
	while (choose)
	{
		if ((choose > 5) || (choose < 1))
			return 0;

		switch (choose)
		{
			case 1:
				getNum(phi);
				Hypo.PointCoordinates(phi);

				break;
			default:
				break;
		}
		menu();
		getNum(choose);
	}
	return 0;
}