using namespace std;
#include<vector>;
#include<algorithm>;
#include<iostream>;
#include<string>;


/**
*  A Finite Scheme for storage and calculation of a finite scheme and comparison to an Analytical Solution including error calculation.
*  \n 
*  \n 
* The Finite Scheme class provides:
* \n-constructors for creating a Finite scheme 
* \n-acessor functions to extract Norms, print output to a screen or csv file
* \n-basic operations like access via [] operator, assignment and comparision
*/



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

	// CONSTRUCTORS
/**
* Default constructor.  Intialize an empty Finite Scheme
*/
	
	
	finite_scheme();  // default constructor

/**
* delta_x constructor.  Initialise finite scheme with a given delta X
*/
	
	
	
	finite_scheme(double delta_x); // Initialise finite scheme with a given delta X





	virtual ~finite_scheme();

	// ACCESSOR METHODS


	/** get method that returns Lmax
	*/
	double get_lmax();
	/** get method that returns L2
	*/
	double get_l2();
	double get_lmax();
	/** get method that returns name of scheme
	*/
	virtual string get_name() { return name;  };



protected:



		// NORMS



	/**
	* protected method that returns a double.
	* It returns Lmax norm from a vector of truncation errors.
	*/
	double calc_lmax(vector<double> in);

	/**
	* protected method that returns a double.
	* It returns L2 norm from a vector of truncation errors.
	*/
	
	double calc_l2(vector<double> in);
	virtual double f(double x);// can this be made more flexible by passing in functions as args?
	virtual double f_prime_x(double x) {return 9 * pow(x, 2) + 2; }; // f'(x);
	virtual vector<double> scheme();

	/**
	* virtual fuction that calculates a discreet scheme
	* 
	*/

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

