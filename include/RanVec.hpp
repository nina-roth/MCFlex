#ifndef __RANVEC_H
#define __RANVEC_H

#include "Point.hpp"

#include <vector>
#include <random>

/*! \class RanVec
 *  \brief A class to generate vectors of random numbers   
 *
 *  Detailed description TODO.
 */

template <typename T>
class RanVec{

	public:
		RanVec(const unsigned long int seed = 0){ 
			mt_rand.seed( seed );
		}
		
		std::vector<T> get_rands(const int n); //!< a vector of n random numbers
		std::vector<Point<T>> get_vec_rands(const int n, const int dim); //!< a vector of dimension dim, containing dim x n random values

	private:
		std::mt19937 mt_rand;
		std::uniform_real_distribution<T> rand_distr{ 0.0, 1.0 };

};

#endif