#include <iostream>
#include <cmath>
using namespace std;

void linearEquation(double a, double b, double y_t, double u_t);
void nonLinearEquation(double a, double b, double c, double d, double y_t, double u_t);

int main()
{
	linearEquation(2, 1.005, 17, 26);
	cout << endl;
	nonLinearEquation(1, 0.003, 0.5, 8, 16, 27);
}

void linearEquation(double a, double b, double y_t, double u_t) {

	cout << "Linear model: " << endl;

	for (int i = 0; i < 10; i++)
	{
		double y_t1 = a * y_t + b * u_t;
		cout << "[" << i + 1 << "]" << " " << "y(t)= " << y_t << " " << "y(t+1)= " << y_t1 << endl;
		y_t = y_t1;
	}
}

void nonLinearEquation(double a, double b, double c, double d, double y_t, double u_t) {

	cout << "Non Linear Model: " << endl;

	double y_t0 = 0;
	double u_t0 = u_t;

	for (int i = 0; i < 10; i++)
	{
		double y_t1 = a * y_t - b * y_t0 * y_t0 + c * u_t + d * sin(u_t0);
		cout << "[" << i + 1 << "]" << " " << "y(t)= " << y_t << " " << "y(t+1)= " << y_t1 << endl;
		y_t0 = y_t;
		y_t = y_t1;
	}
}