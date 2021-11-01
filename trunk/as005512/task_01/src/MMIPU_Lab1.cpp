#include <iostream>

using namespace std;

int main() {
	const double a = 0.5, b = 0.05, c = 0.04, d = 0.004;
	int moments;
	double u_t, y_t, y2_t;
	cout << "Input max count of discrete moments: ";
	cin >> moments;
	if (moments < 1) {
		cout << "Error!";
		return 0;
	}

	cout << "Enter temperature (y(t)): ";
	cin >> y_t;
	cout << "Enter input warm (u(t)): ";
	cin >> u_t;
	
	y2_t = y_t;
	cout << "Linear model:\t" << "Nonlinear model:" << endl;
	for (int i = 0; i < moments; i++) {
		y_t = a * y_t + b * u_t;
		y2_t = a * y2_t - b * pow(y2_t, 2) + c * u_t + d * sin(u_t);
		cout << i + 1 << ") " << y_t << "\t\t" << i + 1 << ") " << y2_t <<  endl;
	}
}