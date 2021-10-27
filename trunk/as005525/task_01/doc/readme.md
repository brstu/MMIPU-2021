# Laboratory work No.1              
              MINISTRY OF EDUCATION OF THE REPUBLIC OF BELARUS
                          EDUCATIONAL INSTITUTION 
                    «BREST STATE TECHNICAL UNIVERSITY»        
                            Department of IIT


                           Laboratory work No.1 


	                                	Completed by the 3rd year student of 
                                            Faculty of Electronic Information Systems
	                                	the group AC-55 Charnetski M.A.
                                 		Checked by Ivanuk D.S.


                                 Brest 2021

## Task 1. Modeling controlled object: 
Write program (C++), which simulates object temperature.

##### Code:
```C++
#include <iostream>
#include "cmath"
using namespace std;


int main()
{
	double a = 6;
	double b = 4;
	double c = 3;
	double d = 2;
	double uT = 5;
	int iT = 20;
	int t;
	double ylinear = 5, ynonlinear = 10;
	cout << "Let us consider that the initial temperature is 20: " << endl;
	cout << "Input time measured in seconds (discrete value not less than 1): "; cin >> t;
	cout << "\t\t\Linear model\t\t\t\t\tNonlinear model" << endl;
	for (int i = 1; i <= t; i++) {
		ylinear = a * ylinear + b * uT;
		ynonlinear = a * ynonlinear - b * pow(ynonlinear, 2) + c * uT + d * sin(uT);
		cout << i << "\t\t" << ylinear << "\t\t\t\t\t\t" << ynonlinear << endl;
	}
}
```