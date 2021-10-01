# Laboratory work No.1              
              MINISTRY OF EDUCATION OF THE REPUBLIC OF BELARUS
                          EDUCATIONAL INSTITUTION 
                    «BREST STATE TECHNICAL UNIVERSITY»        
                            Department of IIT


                           Laboratory work No.1 


	                                	Completed by the 3rd year student of 
                                    Faculty of Electronic Information Systems
	                                	the group AC-55 Chernookiy I.V.
                                 		Checked by Ivanuk D.S.


                                 Brest 2021

## Task 1. Modeling controlled object: 
Write program (C++), which simulate object temperature.

<p align="center">
  <img src ="https://github.com/MrSoulfinder/universityWork_cpp/blob/main/sem_5/1.png">
</p>

##### Code:
```C++
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

double ModelOne(double Yt, double a, double b, double Ut) { // function of first model 
    return a * Yt + b * Ut; 
}

double ModelTwo(double LastYt, double GLastYt, double LastUt, double GLastUt, double a, double b, double c, double d) { // function of second model 
    return a * LastYt - b * GLastYt * GLastYt + c * LastUt + d * sin(GLastUt); 
}

int main() {
    double y0, u0, aL, bL, aN, bN, cN, dN, yKey, yKey2, uKey, uKey2; 
    int NumOfFModelIterations, NumOfSModelIterations;
    
    cout << "--- Please set the values of constants ---" << endl;
    cout << "Input inintial value of y: "; cin >> y0; // user input values of constants 
    cout << "Input initial value of u: "; cin >> u0;

    cout << endl << "--- First Model parametrs ---" << endl;
    cout << "Input value of a-parameter: "; cin >> aL;
    cout << "Input value of b-parameter: "; cin >> bL;

    cout << endl << "--- Second Model parametrs ---" << endl;
    cout << "Input value of a-parameter: "; cin >> aN;
    cout << "Input value of b-parameter: "; cin >> bN;
    cout << "Input value of c-parameter: "; cin >> cN;
    cout << "Input value of d-parameter: "; cin >> dN;

    cout << endl << "--- Number of iterations ---" << endl;
    cout << "First Model (Linear): "; cin >> NumOfFModelIterations; // user input number of iterations
    cout << "Second Model (Nonlinear): "; cin >> NumOfSModelIterations;

    cout << endl << endl << "--- Model One (Linear) ---" << endl;
    yKey = y0; uKey = u0;
    cout << "\t\t\tIteration" << "\t\t\t" << "Yt";

    for (int iterator = 0; iterator < NumOfFModelIterations; iterator++) {
        cout << endl << "Enter Ut: "; cin >> uKey; // user input value of Ut

        yKey = ModelOne(yKey, aL, bL, uKey); // calculation new value of Yt
        cout << "\t\t\t" << iterator + 1 << "\t\t\t\t" << yKey; 
    }
    cout << "" << endl << endl << "--- Model Two (Nonlinear) ---" << endl; // Model One
    yKey = y0; uKey = u0;
    cout << "\t\t\tIteration" << "\t\t\t" << "Yt";

    for (int iterator = 0; iterator < NumOfFModelIterations; iterator++) {
        if (iterator > 0) { // checking is this zero-iteration

            uKey2 = uKey; yKey2 = yKey; // passing data from Yt to Yt-1
            cout << endl << "Enter Ut: "; cin >> uKey; // user unput value of Ut

            yKey = ModelTwo(yKey, yKey2, uKey, yKey2, aN, bN, cN, dN); // calculation new value of Yt
            cout <<"\t\t\t" << iterator + 1 << "\t\t\t\t" << yKey; 
        }
        else {

            uKey2 = 0; yKey2 = 0; // initializing Yt-1 and Ut-1 values
            cout << endl << "Enter Ut: "; cin >> uKey; // user input value of Ut

            yKey = ModelTwo(yKey, yKey2, uKey, yKey2, aN, bN, cN, dN); // calculating new value of Yt
            cout << "\t\t\t" << iterator + 1 << "\t\t\t\t" << yKey;
        }
    }
}
```

##### Result:
<p align="center">
  <img src ="https://github.com/MrSoulfinder/universityWork_cpp/blob/main/sem_5/2.png">
</p>

<p align="center">
  <img src ="https://github.com/MrSoulfinder/universityWork_cpp/blob/main/sem_5/3.png">
</p>
