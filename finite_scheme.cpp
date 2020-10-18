#include "finite_scheme.h"



finite_scheme::finite_scheme()
{

}





finite_scheme::~finite_scheme()
{
}

double finite_scheme::get_lmax()
{
	return lmax;
}

double finite_scheme::get_l1()
{
	return l1;
}

double finite_scheme::get_l2()
{
	return l2;
}


bool comp(double a, double b) {

	return abs(a) < abs(b); // comparison for Lmax to return largest absolute value
}

double finite_scheme::calc_lmax(vector<double> in)
{
	vector<double>::iterator max = max_element(begin(in), end(in),comp); 
	double lmax = *max;
	return lmax;
}

double finite_scheme::calc_l1(vector<double> in)
{
	return 0.0;
}

double finite_scheme::calc_l2(vector<double> in)
{
	double sum = 0.0;
	for (double x : in) {
		sum += x * x;
	}
	return sqrt(sum);  // check whether to extend square root sum. 
	//return sum;
}

double finite_scheme::f(double x){ return 3 * pow(x, 3) + 2 * x + 1; }

vector<double> finite_scheme::scheme()
{

	cout << "\n scheme loop for  " << this->get_name()<<  endl;

	do
	{
		discreet_value = scheme_function(x, delta_x);
		error = discreet_value - f_prime_x(x);
		error_v.push_back(error);
		cout << "x=" << x << "delta_x =" << delta_x << "f_prime_x =" << f_prime_x(x) << "error = " << error << "discreet value =" << discreet_value << endl;
		x += delta_x;
	} while (x <= 1);

	return error_v;
}

double finite_scheme::scheme_function(double x, double delta_x) { return ((f(x + delta_x) - f(x - delta_x)) / delta_x) * 0.5; };

forward_scheme::forward_scheme()
{
	in = this->scheme();
	lmax = this->calc_lmax(in);
	l2 = this->calc_l2(in);


}

double forward_scheme::scheme_function(double x, double delta_x){ return (f(x + delta_x) - f(x)) / delta_x; }


