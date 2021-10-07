#include <iostream>
#include <cmath>
using namespace std;
void Lin(double a, double b, float y_1, float y_2);
void NotLin(double a, double b, double c, double d, float y_1, float y_2);

int main()

{
	setlocale(LC_ALL, "Russian");
	Lin(2, 0.005, 5.0, 3.0);
	NotLin(2, 0.005, 0.055, 0.0005, 5.0, 3.0);
	return 0;
}
void Lin(double a, double b, float y_1, float y_2)

{
	double expr;
	int k;
	cout << "Введите макс значение дискрет моментов линейной модели (n>1): ";
	cin >> k;
	cout << "\t\t Линейная модель" << endl;
	if (k > 0) {
		for (int i = 0; i <= k; ++i)
		{
			expr = a * y_2 + b * y_1;
			y_2 = expr;
			cout << "y(t" << i << ") = " << y_2 << endl;
		}
	}
	else
	{
		cout << "Неверное значение " << endl;
	}

}
void NotLin(double a, double b, double c, double d, float y_1, float y_2)

{
	double expr_1 = 0;
	double expr_2;
	int j;
	cout << "Введите макс значение дискрет моментов нелинейной модели (n>1): ";
	cin >> j;
	cout << "\t\t Нелинейная модель" << endl;
	if (j > 0) {
		for (int i = 0; i <= j; ++i)
		{
			expr_2 = a * y_2 - b * pow(expr_1, 2) + c * y_1 + d * sin(y_1);
			expr_1 = y_2;
			y_2 = expr_2;
			cout << "y(t" << i << ")" << " = " << y_2 << endl;
		}
	}
	else 
	{
		cout << "Неверное значение " << endl;
	}
	
}

