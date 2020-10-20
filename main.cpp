#include <cmath>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
#include "finite_scheme.h"
using namespace std;

// demonstration of finite scheme objects outputting l0 l2 max and errors and output files.   Finite scheme object takes delta x 
//as argument an object can be created for any delta x.


int main()


{
	
	forward_scheme fd_01 = forward_scheme(0.1);
	center_scheme cd_01 = center_scheme(0.1);

	fd_01.print();
	fd_01.output();
	cout << fixed << setprecision(10);
	cout << "\n l2 norm= " << fd_01.get_l2();
	cout << "\n lmax norm= " << fd_01.get_lmax();

	cd_01.print();
	cd_01.output();
	cout << fixed << setprecision(10);
	cout << "\n l2 norm= " << cd_01.get_l2();
	cout << "\n lmax norm= " << cd_01.get_lmax();


	forward_scheme fd_001 = forward_scheme(0.01);
	center_scheme cd_001 = center_scheme(0.01);

	fd_001.print();
	fd_001.output();
	cout << fixed << setprecision(10);
	cout << "\n l2 norm= " << fd_001.get_l2();
	cout << "\n lmax norm= " << fd_001.get_lmax();

	cd_001.print();
	cd_001.output();
	cout << fixed << setprecision(10);
	cout << "\n l2 norm= " << cd_001.get_l2();
	cout << "\n lmax norm= " << cd_001.get_lmax();



	forward_scheme fd_0001 = forward_scheme(0.01);
	center_scheme cd_0001 = center_scheme(0.01);

	fd_0001.print();
	fd_0001.output();
	cout << fixed << setprecision(10);
	cout << "\n l2 norm= " << fd_0001.get_l2();
	cout << "\n lmax norm= " << fd_0001.get_lmax();

	cd_0001.print();
	cd_0001.output();
	cout << fixed << setprecision(10);
	cout << "\n l2 norm= " << cd_0001.get_l2();
	cout << "\n lmax norm= " << cd_0001.get_lmax();












  return 0;


}








