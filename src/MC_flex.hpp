#ifndef __MC_FLEX_H
#define __MC_FLEX_H
#include <stdexcept>
//#include <iostream>
/*! \brief A class to do Monte-Carlo Integrationw with a user defined function   
 *
 *  Detailed description TODO.
 */

class MC_integrate{

	public:
		//MC_integrate(int dim, unsigned long int n, double vol, std::vector<double> b,
		//			 unsigned long int s=0);
		//MC_integrate(int dim, unsigned long int n, double vol, std::vector<double> b, unsigned long int s, 
		//			 std::vector<double> (*weight_function)(std::vector<Point>, std::vector<double>) );
		//MC_integrate(const int ndim_, const unsigned long int npoints_, const double volume_, std::vector<double> border_, 
		//	         const unsigned long int seed_, std::vector<double> (*weight_function)(std::vector<Point>, std::vector<double>) ) 
		//: ndim(ndim_), npoints(npoints_), volume(volume_), seed(seed_){
		// 	if(!border_.empty()){ border = border_; }
		// 	else{throw std::runtime_error("'Border' is empty"); }

		// 	if()
		// 	elseget_weights = weight_function;
		// }

		MC_integrate(const int ndim_, const unsigned long int npoints_, const double volume_, std::vector<double> border_, 
			         const unsigned long int seed_, std::vector<double> (*weight_function)(std::vector<Point>, std::vector<double>) ) 
		: ndim(ndim_), npoints(npoints_), volume(volume_), border(border_), seed(seed_), get_weights(weight_function) 
		{

			if( border.empty() ){throw std::runtime_error("MC_integrate: 'Border' is empty. Aborting...");}
			if (border.size() != ndim ){throw std::runtime_error("MC_integrate: Dimensions of border do not match. Aborting...");}

		}


		void calculate();
		//void set_values(long unsigned int, double, std::vector<double>, long unsigned int);
		double result;
		double error;
		~MC_integrate(){};

	private:
		const int ndim;
		const unsigned long int npoints;
		const double  volume;
		const unsigned long int seed;
		std::vector<double> border;
		std::vector<double> (*get_weights)(std::vector<Point>, std::vector<double>);

};
#endif