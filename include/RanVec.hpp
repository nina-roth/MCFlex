#ifndef __RANVEC_H
#define __RANVEC_H

#include <gsl/gsl_rng.h> //link -lgsl and -lgslcblas at the very end
#include <memory>

/*! \class RanVec
 *  \brief A class to generate vectors of random numbers   
 *
 *  Detailed description TODO.
 */

template <typename T>
class RanVec{

	public:
		RanVec(const unsigned long int seed = 0){ gsl_rng_set( generator.get(), seed ); }
		
		std::vector<T> get_rands(const int n); //!< a vector of n random numbers
		std::vector<Point<T>> get_vec_rands(const int n, const int dim); //!< a vector of dimension dim, containing dim x n random values

	private:
		std::shared_ptr<gsl_rng> generator{ gsl_rng_alloc(gsl_rng_ranlxd2), gsl_rng_free }; //! the random number generator


};

#endif