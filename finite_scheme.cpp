#include <iomanip>
#include "finite_scheme.h"




finite_scheme::finite_scheme(double delta_x){

	discreet_value = 0.0;
	l1 = 0.0;
	l2 = 0.0;
	lmax = 0.0;
	error = 0.0;
}

finite_scheme::finite_scheme()
{
	discreet_value = 0.0;
	l1 = 0.0;
	l2 = 0.0;
	lmax = 0.0;
	error = 0.0;
}



finite_scheme::~finite_scheme()
{
}

double finite_scheme::get_lmax()
{
	return lmax;
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



double finite_scheme::calc_l2(vector<double> in)
{
	double sum = 0.0;
	for (double x : in) {
		sum += x * x;
	}
	return sqrt(sum) /(1 / delta_x); 
	
}

double finite_scheme::f(double x){ return 3 * pow(x, 3) + 2 * x + 1; }

vector<double> finite_scheme::scheme()
{
	
	

	do
	{
		discreet_value = scheme_function(x, delta_x);
		discreet_values.push_back(discreet_value);
		error = discreet_value - f_prime_x(x);
		error_v.push_back(error);
		x += delta_x;
	} while (x <= 1 + (delta_x / 2));

	return error_v;
}

double finite_scheme::scheme_function(double x, double delta_x) { return ((f(x + delta_x) - f(x - delta_x)) / delta_x) * 0.5; };

forward_scheme::forward_scheme(double a)
{
	delta_x = a;
	in = this->scheme();
	lmax = this->calc_lmax(in);
	l2 = this->calc_l2(in);


}

void forward_scheme::print()
{
		cout << fixed << setprecision(5);
		cout << this->get_name() << " For dx = " << delta_x << endl;
		cout << "x     |  " << "delta_x   |  " << "f_prime_x     |  " << "error  |  " << "discreet value" << endl;
	for (int i = 0; i < error_v.size();i++){
		cout << delta_x*(i) << "  |    " << delta_x << "    |      " << f_prime_x(delta_x * (i)) << "      |   " << error_v[i] << "  |      " << discreet_values[i] << endl;

	}

			
}

double forward_scheme::scheme_function(double x, double delta_x){ return (f(x + delta_x) - f(x)) / delta_x; }


center_scheme::center_scheme(double a)
{
	delta_x = a;
	in = this->scheme();
	lmax = this->calc_lmax(in);
	l2 = this->calc_l2(in);


}

center_scheme::center_scheme()
{
}

void center_scheme::print()
{
	cout << fixed << setprecision(5);
	cout << this->get_name() << " For dx = " << delta_x << endl;
	cout << "x     |  " << "delta_x   |  " << "f_prime_x     |  " << "error  |  " << "discreet value" << endl;
	for (int i = 0; i < error_v.size(); i++) {
		cout << delta_x * (i) << "  |    " << delta_x << "    |      " << f_prime_x(delta_x * (i)) << "      |   " << error_v[i] << "  |      " << discreet_values[i] << endl;

	}


}

double center_scheme::scheme_function(double x, double delta_x) { return ((f(x + delta_x) - f(x - delta_x)) / delta_x) * 0.5; };


