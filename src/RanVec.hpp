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
		
		std::vector<double> get_rands(int n);
		std::vector<Point> get_vec_rands(int n, int dim);
		~RanVec(){gsl_rng_free(generator);}

	private:
		gsl_rng* generator = nullptr;
		unsigned long int seed;

};

#endif