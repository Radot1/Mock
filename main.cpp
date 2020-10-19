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
	
	double x =0 ;
	double delta_x = 0.1;


	
	fs.open(filename);



	fs << "x" << ", " << "fwd" << ", " << "fwd error" << ", " << "back" << ", " << "back error" << ", " << "center" <<
		", " << "center error" << ", " << "f'(x)" << " ," << "dx" << endl;




		 center_scheme cnt = center_scheme(0.1);
		 forward_scheme fd = forward_scheme(0.1);

		 cout << "finite_Scheme class lmax calc. cnt = " << cnt.get_lmax() << endl;
		 cout << "forward scheme class lmax calc. fd = " << fd.get_lmax() << endl;
		 cout << "finite_Scheme class l2 calc. fd = " << fd.get_l2() << endl;
		 cout << "finite_Scheme class l2 calc. cnt = " << cnt.get_l2() << endl;


		 center_scheme cnt_001 = center_scheme(0.01);
		 forward_scheme fd_001 = forward_scheme(0.01);

		 cout << "finite_Scheme class lmax calc. cnt = " << cnt_001.get_lmax() << endl;
		 cout << "forward scheme class lmax calc. fd = " << fd_001.get_lmax() << endl;
		 cout << "finite_Scheme class l2 calc. fd = " << fd_001.get_l2() << endl;
		 cout << "finite_Scheme class l2 calc. cnt = " << cnt_001.get_l2() << endl;



  fs.close();

  cout << "enter to stop" << endl;
  cin.get();
  return 0;


}








