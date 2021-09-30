#include "stdafx.h"
#include "linear.h"
#include "notlinear.h"
#include <iostream>

using namespace std;


int main() {
	setlocale(0, "");
	linear lin;
	notlinear notlin;
	lin.ShowResults();
	cout << endl << endl;
	notlin.ShowResults();
	return 0;
}