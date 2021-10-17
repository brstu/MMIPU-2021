#include <iostream>

using namespace std;

int main() {
	double K, T, Td, T0, t, k, kMax, q0, q1, q2;
	T = 0.1;
	K = 10;
	Td = 50;
	T0 = 1;
	t = 4;
	k = 0.1;
	q0 = K * (1 + Td / T0);
	q1 = -K * (1 + 2 * Td / T0 - T0 / T);
	q2 = K * Td / T0;
	kMax = t / T0;
	double* u = new double[ceil(kMax)] {0};
	double* e = new double[ceil(kMax)] {0};
	double* del_u = new double[ceil(kMax)] {0};
	del_u[0] = q0*e[0];
	del_u[1] = q0 * e[1] + q1 * e[0];
	del_u[2] = q0 * e[2] + q1 * e[1] + q2 * e[0];
	while (k < kMax) {

	}
	delete[] u;
	delete[] e;
	delete[] del_u;
}