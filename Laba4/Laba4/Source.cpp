#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#define PI 3.14159265

using namespace std;

class triangle {

protected:

	double a, b, c;

public:

	triangle() {

		a = 0;

		b = 0;

		c = 0;

	}

	triangle(double _a, double _b, double _c) {

		a = _a;

		b = _b;

		c = _c;

	}

	bool it_exist() {

		if ((a + b > c) && (a + c > b) && (b + c > a) && (a != 0) && (b != 0) && (c != 0))

			return true;

		else

			return false;

	}

	void set() {

		double _a, _b, _c;

		cout << "Enter sides: \n";

		while (!it_exist()) {

			cin >> _a; cin >> _b; cin >> _c;

			a = _a;

			b = _b;

			c = _c;

			cout << "------------- \n";

		}

	}

	double perimeter() {

		return (a + b + c);

	}

	double area() {

		double p = perimeter() / 2;

		return(sqrt(p * (p - a) * (p - b) * (p - c)));

	}

	void angles() {

		double alph = acos((a * a + c * c - b * b) / (2 * a * c)) * 180 / PI;

		double beta = acos((a * a + b * b - c * c) / (2 * a * b)) * 180 / PI;

		double gamm = acos((b * b + c * c - a * a) / (2 * b * c)) * 180 / PI;

		cout << "Alpha: " << alph << " Beta: " << beta << " Gamma: " << gamm << endl;

	}

	void get_info() {

		cout << "Sides: \n" << "a: " << a << " b: " << b << " c: " << c << endl;

		cout << "Perimeter: " << perimeter() << endl;

		cout << "Area: " << area() << endl;

		angles();

		cout << "------------- \n";

	}

};

class pryamo_triangle : public triangle {

public:

	pryamo_triangle() :triangle() {}

	pryamo_triangle(double _ea) :triangle(_ea, _ea, _ea) {}

	bool it_exist() {

		double alph = acos((a * a + c * c - b * b) / (2 * a * c)) * 180 / PI;

		double beta = acos((a * a + b * b - c * c) / (2 * a * b)) * 180 / PI;

		double gamm = acos((b * b + c * c - a * a) / (2 * b * c)) * 180 / PI;

		if (alph == 90 || beta == 90 || gamm == 90)

			return true;

		else

			return false;

	}

	double perimeter() {

		return(a + b + c);

	}

	double area() {

		double p = perimeter() / 2;

		return(sqrt(p * (p - a) * (p - b) * (p - c)));

	}

	void angle() {

		double alph = acos((a * a + c * c - b * b) / (2 * a * c)) * 180 / PI;

		double beta = acos((a * a + b * b - c * c) / (2 * a * b)) * 180 / PI;

		double gamm = acos((b * b + c * c - a * a) / (2 * b * c)) * 180 / PI;

		cout << "Alpha: " << alph << " Beta: " << beta << " Gamma: " << gamm << endl;

	}

	void get_info() {

		cout << "Sides: \n" << "a: " << a << " b: " << b << " c: " << c << endl;
		cout << "Gipotenuza: " << gipotenuza() << endl;

		cout << "Perimeter: " << perimeter() << endl;

		cout << "Area: " << area() << endl;

		angle();

		cout << "------------- \n";

	}
	double gipotenuza()
	{
		double gip = max(max(a, b), c);
		return gip;
	}

};

int main()

{

	double max = 0;

	int n = 0;
	double	mingip = 0;
	const int K = 3;

	pryamo_triangle deff[K];

	triangle ravn[K];

	deff[0].set();
	deff[0].get_info();
	mingip = deff[0].gipotenuza();
	for (int i = 1; i < K; i++) {

		deff[i].set();

		if (mingip > deff[i].gipotenuza())
		{
			mingip = deff[i].gipotenuza();
			n = i;
		}

		deff[i].get_info();

	}

	cout << "Smallest gipotenuza: " << n + 1 << " \n \n";

	for (int i = 0; i < K; i++) {

		ravn[i].set();

		if (max < ravn[i].area()) {

			max = ravn[i].area();

			n = i;

		}

		ravn[i].get_info();

	}

	cout << "Max area triangle: " << n + 1 << " \n \n";

	return 0;

}
