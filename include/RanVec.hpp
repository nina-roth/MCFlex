#ifndef __RANVEC_H
#define __RANVEC_H

//#include <memory>
#include <gsl/gsl_rng.h> //link -lgsl and -lgslcblas at the very end
//#include <stdexcept>

/*! \class RanVec
 *  \brief A class to generate vectors of random numbers   
 *
 *  Detailed description TODO.
 */

template <typename T>
class RanVec{

	public:
		RanVec(const unsigned long int seed = 0);
		
		std::vector<T> get_rands(const int n); //!< a vector of n random numbers
		std::vector<Point<T>> get_vec_rands(const int n, const int dim); //!< a vector of dimension dim, containing dim x n random values
		~RanVec() { gsl_rng_free(generator); generator=nullptr; }

		RanVec(const RanVec& other) = default; 
    	RanVec& operator=(const RanVec& other) = default;
    	RanVec(RanVec&& other) = default;
    	RanVec& operator=(RanVec&& other) = default;

	private:
		gsl_rng* generator;

};

#endif