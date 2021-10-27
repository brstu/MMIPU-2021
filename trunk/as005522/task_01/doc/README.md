# Laboratory work No.1              
              MINISTRY OF EDUCATION OF THE REPUBLIC OF BELARUS
                          EDUCATIONAL INSTITUTION 
                    «BREST STATE TECHNICAL UNIVERSITY»        
                            Department of IIT


                           Laboratory work No.1 


                                    Completed by the 3rd year student of 
                                            Faculty of Electronic Information Systems
                                    the group AC-55 Rodion E.S.
                                     Checked by Ivanuk D.S.


                                 Brest 2021

## Task 1. Modeling controlled object: 
Write program (C++), which simulates object temperature.

##### Code:
```C++
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double a, b, c, d, y0, y1, y2, y, ut = 5, ut1 = 3;

	cout << "Input a: ";
	cin >> a;


	cout << "Input b: ";
	cin >> b;


	cout << "Input c: ";
	cin >> c;


	cout << "Input d: ";
	cin >> d;

	cout << "Input room temperature: ";
	cin >> y0;

	int t;
	cout << "Input the time during which the study will be conducted: ";
	cin >> t;

	if (t > 0)
	{

		cout << "Input temperature of our object: ";
		cin >> y1;
		y2 = y1;
		cout << "\t\t\tLinear model\t\t\tNonlinear model" << endl;
		cout << "(0)" << "\t\t\t" << y1 << "\t\t\t\t" << y2 << endl;
		y1 = a * y1 + b * ut;
		for (int i = 1; i <= t; i++) {
			y = y1;
			y1 = a * y1 + b * ut;
			y2 = a * y2 - b * pow(y, 2) + c * ut + d * sin(ut1);
			cout <<"(" << i << ")" << "\t\t\t" << y1 << "\t\t\t\t" << y2 << endl;
		}


	}
	else
	{
		cout << "invalid" << endl;
	}

	return 0;

}
```                            
