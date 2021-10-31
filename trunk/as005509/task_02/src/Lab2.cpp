#include <iostream>
#include <math.h>
#include <fstream>
#define J 1
#define a 0.5
#define b 0.0001
#define c 0.01

using namespace std;
double fun(double*, int);
int main() {
	double K, T, Td, T0, t, q0, q1, q2;
	int k;
	T = 0.1;
	K = 1;
	Td = 0.01;
	T0 = 1;
	t = 10;
	k = 0.1;
	q0 = K * (1 + Td / T0);
	q1 = -K * (1 + 2 * Td / T0 - T0 / T);
	q2 = K * Td / T0;
	k = ceil(t / T0);
	double* u = new double[k] {0};
	double* y = new double[k] {0};
	double* e = new double[k] {0};
	double* del_u = new double[k] {0};
	y[0] = 0;
	e[0] = 0;
	del_u[0] = q0 * e[0];
	y[0] += del_u[0];

	y[1] = fun(y, 1);
	e[1] = y[1] - y[0];
	del_u[1] = q0 * e[1] + q1 * e[0];
	y[1] += del_u[1];
	
	for (int i = 2; i < k; i++) {
		y[i] = fun(y, i);
		e[i] = y[i] - y[i - 1];
		del_u[i] = q0 * e[i] + q1 * e[i - 1] + q2 * e[i - 2];
		y[i] += del_u[i];
	}
	ofstream file("out.txt");
	for (int i = 0; i < k; i++) {
		//cout << y[i] << ' ' << e[i] << ' ' << del_u[i] << endl;
		file << i << " second:  " << y[i] << endl;
	}
	file.close();
	delete[] u;
	delete[] y;
	delete[] e;
	delete[] del_u;
}

double fun(double* y, int i) {
	return (a * y[i - 1] - b * pow(y[i - 1], 2) + J + c * sin(J));
}