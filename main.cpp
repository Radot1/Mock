#include <cmath>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
#include "finite_scheme.h"
using namespace std;



//  typedef double (*func_ptr)(double u, double t); try to use typdef for passing in lambda as arg.
// create a name for the file output



int main()

// for purposes of demonstration, an interactive loop is included that lets you choose a scheme, a delta x value, and the
// choice to print your file to the screen or a csv;

{
	int c;
	double dx;
	int print;
	finite_scheme scheme;

	do
	{
		cout << "Choose scheme 1. forward difference 2. Central  3 to exit" << endl;
		cin >> c;
		if (c == 3) { break; }
		cout << "Choose delta x" << endl;
		cin >> dx;
		cout << "Choose scheme 1. Print to Screen 2. Print to file" << endl;
		cin >> print;

		switch (c) {
		case 1:
			scheme = forward_scheme(dx);
			break;
		case 2:
			scheme = center_scheme(dx);
			break;
		default:
			break;

		}

		switch (print) {
		case 1:
			break;
		case 2:
			break;
		default:
			break;

		}




	} while (true);
	


  return 0;


}








