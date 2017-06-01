#ifndef __RANVEC_H
#define __RANVEC_H

#include <gsl/gsl_rng.h> //link -lgsl and -lgslcblas at the very end

/*! \brief A class to generate vectors of random numbers   
 *
 *  Detailed description TODO.
 */

class RanVec{

	public:
		RanVec(unsigned long int seed = 0);
		//Ran ();
		double get_rand();
		std::vector<double> get_rands(long unsigned int);
		std::vector<Point> get_vec_rands(long unsigned int, int);
		~RanVec();

	private:
		gsl_rng* generator = NULL;

};

#endif