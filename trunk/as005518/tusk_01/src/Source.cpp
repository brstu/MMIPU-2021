#include <iostream>

using namespace std;

int main() {
	const double a = 0.35, b = 0.21, c = 0.623, d = 0.321;
	int t = 0;
	double f_t = 0, y_t = 0, y2_t = 0;
	cout << "Enter the time: ";
	cin >> t;
	if (t < 1) {
		cout << "Wrong time!";
		return 0;
	}
	cout << "Enter input warm in Joule: ";
	cin >> f_t;
	cout << "Enter temperature in Celsius: ";
	cin >> y_t;
	y2_t = y_t;
	cout << "Linear model:\t" << "Nonlinear model:" << endl;
	for (int i = 0; i < t; i++) {
		y_t = a * y_t + b * f_t;
		y2_t = a * y2_t - b * pow(y2_t, 2) + c * f_t + d * sin(f_t);
		cout << y_t << "\t\t" << y2_t << endl;
	}
} 