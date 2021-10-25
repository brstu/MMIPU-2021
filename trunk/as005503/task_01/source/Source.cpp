#include <iostream>
#include <cmath>
using namespace std;
void Lin(double a, double b, double y1, double y2);
void Nonlin(double a, double b, double c, double d, double y1, double y2);

int main()

{
	Lin(2, 0.005, 5, 3);
	Nonlin(2, 0.005, 0.055, 0.0005, 5, 3);
	return 0;
}
void Lin(double a, double b, double y1, double y2)

{
	double as;
	int Nlin;
	cout << "Input max count of discrete moment for NonLinearModel (n>1): ";
	cin >> Nlin;
	cout << "\t\t LinearModel" << endl;
	for (int i = 0; i <= Nlin; ++i)
	{
		as = a * y2 + b * y1;
		y2 = as;
		cout << "y(t" << i << ") = " << y2 << endl;
	}
}
void Nonlin(double a, double b, double c, double d, double y1, double y2)

{
	double as_1 = 0;
	double as_2;
	int NNlin;
	cout << "Input max count of discrete moment for NonLinearModel (n>1): ";
	cin >> NNlin;
	cout << "\t\t Nonlinear" << endl;
	for (int i = 0; i <= NNlin; ++i)
	{
		as_2 = a * y2 - b * as_1 * as_1 + c * y1 + d * sin(y1);
		as_1 = y2;
		y2 = as_2;
		cout << "y(t" << i << ")" << " = " << y2 << endl;
	}
}