using namespace std;
#include<vector>;
#include<algorithm>;
#include<iostream>;
#include<string>;
class finite_scheme
{
	public:
	string name = "finite Scheme";
	double lmax;
	double l2;
	double l1;
	double x = 0;
	double delta_x = 0.1;
	double error;
	double discreet_value;
	vector<double> error_v;
	vector<double> discreet_values;
	vector<double> in;


public:
	finite_scheme(double delta_x);
	finite_scheme();
	virtual ~finite_scheme();
	double get_lmax();
	double get_l1();
	double get_l2();
	virtual string get_name() { return name;  };

	// functions to get norms;

protected:

	// functions to calculate norms;
	double calc_lmax(vector<double> in);
	double calc_l1(vector<double> in);
	double calc_l2(vector<double> in);
	virtual double f(double x);// can this be made more flexible by passing in functions as args?
	virtual double f_prime_x(double x) {return 9 * pow(x, 2) + 2; }; // f'(x);
	virtual vector<double> scheme();
	virtual double scheme_function(double x, double delta_x);

};


class forward_scheme : public finite_scheme{

	string name = "forward Scheme";

	public:
		forward_scheme(double delta_x);
		virtual string get_name() { return this->name; };
		

protected:
	virtual double scheme_function(double x, double delta_x);

};
class center_scheme : public finite_scheme {

	string name = "center Scheme";

public:
	center_scheme(double delta_x);
	virtual string get_name() { return this->name; };


protected:
	virtual double scheme_function(double x, double delta_x);

};

