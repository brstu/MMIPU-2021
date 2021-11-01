# Laboratory work No.1              
              MINISTRY OF EDUCATION OF THE REPUBLIC OF BELARUS
                          EDUCATIONAL INSTITUTION 
                    «BREST STATE TECHNICAL UNIVERSITY»        
                            Department of IIT


                           Laboratory work No.1 


	                                	Completed by the 3rd year student of 
                                            Faculty of Electronic Information Systems
	                                	the group AC-55 Artysyuk I.V.
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
	double a, b, c, d, y, yL, yNL, ut; 
	int t;
	cout << "Input time measured in seconds (discrete value not less than 1): "; cin >> t;
	if (t > 0)
	{
		cout << "Input value of parameter a: "; cin >> a;
		cout << "Input value of parameter b: "; cin >> b;
		cout << "Input value of parameter c: "; cin >> c;
		cout << "Input value of parameter d: "; cin >> d;
		cout << "Input value of parameter ut: "; cin >> ut;
		cout << "Input initial temperature of controlled object: ";
		cin >> y;
		yL = yNL = y;
		cout << endl;
		cout << "\t\t\Linear model\t\t||\t\t\tNonlinear model" << endl;
		for (int i = 1; i <= t; i++) {
			yL = a * yL + b * ut;
			yNL = a * yNL - b * pow(yNL, 2) + c * ut + d * sin(ut);
			cout << "y(" << i << ")" << "\t\t" << yL << "\t\t\t||\t\t\t" << yNL << endl;
		}
	}
	else
	{
		cout << "Error. Input correct number." << endl;
	}
	return 0;
}
```