#ifndef __MC_FLEX_H
#define __MC_FLEX_H

/*! \brief A class to do Monte-Carlo Integrationw with a user defined function   
 *
 *  Detailed description TODO.
 */

class MC_integrate{

	public:
		MC_integrate(int dim, unsigned long int n, double vol, std::vector<double> b,
					 unsigned long int s=0);
		MC_integrate(int dim, unsigned long int n, double vol, std::vector<double> b, unsigned long int s, 
					 std::vector<double> (*weight_function)(std::vector<Point>, std::vector<double>) );
		std::vector<double> (*get_weights)(std::vector<Point>, std::vector<double>);
		void calculate();
		void set_values(long unsigned int, double, std::vector<double>, long unsigned int);
		int get_values();
		double result;
		double error;
		~MC_integrate();

	private:
		int ndim;
		unsigned long int npoints;
		double  volume;
		unsigned long int seed;
		std::vector<double> border;

};
#endif