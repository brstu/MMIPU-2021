

#include <iostream>
#include "cmath"
#include "math.h"
using namespace std;

int main()
{
	
	setlocale(LC_ALL, "Russian");
	int i;
	float a = 3, b = 0.33, c = 0.126, d = 0.1546;
	float y0 = 12.5, y1, y2, y;
	float u_t = 7.5;
	float ut_1 = 4.5;
	float t;

	cout << "Введите максимальное значение дискретных моментов, не меньше 1: ";
	cin >> t;


	cout << "Введите входную температуру объекта: ";
	cin >> y1;
	y2 = y1;
	cout << "Линельная модель\nНелинейная модель" << endl;
	cout << 0 << "\t" << y1 << "\t" << y2 << endl;
	y1 = a * y1 + b * u_t;
	y = y1;
	for (i = 1; i < t; i++) {
		y1 = a * y1 + b * u_t;
		y2 = a * y2 - b * pow(y, 2) + c * u_t + d * sin(ut_1);
		cout << i << "\t" << y1 << "\t" << y2 << endl;
	}
	return 0;
}

	
