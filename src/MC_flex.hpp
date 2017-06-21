#ifndef __MC_FLEX_H
#define __MC_FLEX_H
#include <stdexcept>
//#include <iostream>

/*! \class MC_integrate
 * \brief A class to do Monte-Carlo Integration with a user defined function   
 *
 *  Detailed description TODO.
 */

class MC_integrate{

	public:
		MC_integrate(const int ndim_, const int npoints_, const double volume_, std::vector<double> border_, 
			         const unsigned long int seed_, std::vector<double> (*weight_function)(std::vector<Point>, std::vector<double>) ) 
		: ndim(ndim_), npoints(npoints_), volume(volume_), border(border_), seed(seed_), get_weights(weight_function) 
		{

			if ( border.empty() ){throw std::runtime_error("MC_integrate: 'Border' is empty. Aborting...");}
			if ( border.size() != ndim ){throw std::runtime_error("MC_integrate: Dimensions of border do not match. Aborting...");}

		}

		void calculate(); //!< perform the calculation
		double result() const {return result_; }//!< the MC-integration result
		double error() const {return error_; }//!< the MC-integration error -- sqrt( Var(result) )
		~MC_integrate(){};

	private:
		const int ndim; //!< the dimensions of the integration volume
		const int npoints; //!< the number of randomly drawn integration points
		const double volume; //!< the volume of the integration region
		const unsigned long int seed; //!< seed for the random generator
		std::vector<double> border; //!< the integration borders
		std::vector<double> (*get_weights)(std::vector<Point>, std::vector<double>); //!< the weight function
		double result_;
		double error_;

};
#endif