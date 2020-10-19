#include <cmath>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
#include "finite_scheme.h"
using namespace std;




int main()


{
	
	forward_scheme fd_01 = forward_scheme(0.01);
	center_scheme cd_01 = center_scheme(0.01);

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









  return 0;


}








