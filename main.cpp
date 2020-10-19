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

{
	ofstream outputFile;
	ofstream fs;
	string filename = "exampleOutput.csv";

	cout << setprecision(10);


	
	fs.open(filename);



	fs << "x" << ", " << "fwd" << ", " << "fwd error" << ", " << "back" << ", " << "back error" << ", " << "center" <<
		", " << "center error" << ", " << "f'(x)" << " ," << "dx" << endl;




		 center_scheme cnt = center_scheme(0.1);
		 forward_scheme fd = forward_scheme(0.1);
		 
		 fd.print();
		 cout << setprecision(8);
		 cout << "L0 = " << fd.get_lmax() << endl;
		 cout << "L2 = " << fd.get_l2() << endl << endl;

		 cnt.print();
		 cout << setprecision(8);
		 cout << "L0 = " << cnt.get_lmax() << endl;
		 cout << "L2= " << cnt.get_l2() << endl << endl;


		 center_scheme cnt_001 = center_scheme(0.01);
		 forward_scheme fd_001 = forward_scheme(0.01);

		 fd_001.print();
		 cout << setprecision(8);
		 cout << "L0 = " << fd_001.get_lmax() << endl;
		 cout << "L2 = " << fd_001.get_l2() << endl << endl;

		 cnt_001.print();
		 cout << setprecision(8);
		 cout << "L0 = " << cnt_001.get_lmax() << endl;
		 cout << "L2= " << cnt_001.get_l2() << endl << endl;



  fs.close();

  cout << "enter to stop" << endl;
  cin.get();
  return 0;


}








