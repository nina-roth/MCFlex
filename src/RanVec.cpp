#include "Point.hpp"
#include "RanVec.hpp"

/*! \brief A class to generate vectors of random numbers   
 *
 *  Detailed description TODO.
 */

RanVec::RanVec (unsigned long int seed) {

			const gsl_rng_type* T;
			T = gsl_rng_ranlxd2;
			generator = gsl_rng_alloc (T);
			gsl_rng_set(generator, seed);
			//std::cout << "Seed is " << seed << std::endl;

}

// RanVec::~RanVec(){
// 	gsl_rng_free(generator);
// }

std::vector<Point> RanVec::get_vec_rands(long unsigned int n, int dim){
	std::vector<Point> rnd(n, Point(dim));
	double dummy;
	for(long unsigned int i=0;i<n;i++){
	 	for(int j=0; j<dim; j++){
	 		dummy=gsl_rng_uniform(this->generator);
	 		//std::cout << dummy << std::endl;
	 		rnd[i].coords.push_back(dummy);
	 	}
	}

	return rnd;
}

// double RanVec::get_rand(){

// 	return gsl_rng_uniform(this->generator);
// }

std::vector<double> RanVec::get_rands(long unsigned int n){
	std::vector<double> rnd(n);
	for(long unsigned int i=0;i<n;i++){
	 	rnd[i]=gsl_rng_uniform(this->generator);
	}
	return rnd;
}