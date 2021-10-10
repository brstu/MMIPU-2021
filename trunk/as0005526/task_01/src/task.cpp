#include <iostream>
#include <conio.h>
#include "windows.h"

using namespace std;

int main() {
	long t = 0, n = 1;
	double f_t = 0;
	const double a = 0.9, b = 0.001, c = 1, d = 0.123;
	cout << "Enter the time in seconds more than 1" << endl;
	cin >> n;
	if (n <= 1) {
		cout << "Incorrect time" << endl;
		exit(0);
	}
	double* y1_t = new double[n + 1]{ 0 };
	double* y2_t = new double[n + 1]{ 0 };
	cout << "Enter input warm in Joule" << endl;
	cin >> f_t;
	cout << "Enter room temperature in Celsius" << endl;
	cin >> y1_t[0];
	y2_t[0] = y1_t[0];
	system("cls");
	cout << "Time: " << t + 1 << " seconds" << endl;
	y1_t[t + 1] = a * y1_t[t] + b * f_t;
	y2_t[t + 1] = a * y2_t[t] - b * pow(y2_t[0], 2) + c * f_t + d * sin(f_t);
	cout << "First object temperature:" << endl << y1_t[t] << " oC" << endl;
	cout << "Second object temperature:" << endl << y2_t[t] << " oC" << endl;
	for (t = 1; t < n; t++) {
		y1_t[t + 1] = a * y1_t[t] + b * f_t;
		y2_t[t + 1] = a * y2_t[t] - b * pow(y2_t[t - 1], 2) + c * f_t + d * sin(f_t);
		Sleep(330);
		system("cls");
		cout << "Time: " << t + 1 << " seconds" << endl;
		cout << "First object temperature:" << endl << y1_t[t] << " oC" << endl;
		cout << "Second object temperature:" << endl << y2_t[t] << " oC" << endl;
	}
	delete[] y1_t;
	delete[] y2_t;
}