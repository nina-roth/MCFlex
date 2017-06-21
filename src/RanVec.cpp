#include "Point.hpp"
#include "RanVec.hpp"
#include <stdexcept>

RanVec::RanVec (const unsigned long int seed) {

			const gsl_rng_type* T;
			T = gsl_rng_ranlxd2;
			generator = gsl_rng_alloc (T);
			gsl_rng_set(generator, seed);

}

std::vector<Point> RanVec::get_vec_rands(const int n, const int dim){
	std::vector<Point> rnd(n, Point(dim));
	if( rnd.empty() ){
		throw std::runtime_error("MC_integrate: Illegal parameters for RanVec::get_vec_rands(). Aborting...");
	}
	for(int i=0;i<n;i++){
	 	for(int j=0; j<dim; j++){
	 		rnd[i].coords.push_back( gsl_rng_uniform(generator) );
	 	}
	}

	return rnd;
}

std::vector<double> RanVec::get_rands(const int n){
	std::vector<double> rnd(n);
	if( rnd.empty() ){
		throw std::runtime_error("MC_integrate: Illegal parameters for RanVec::get_rands(). Aborting...");
	}
	for(int i=0; i<n; i++){
	 	rnd[i] = gsl_rng_uniform(generator);
	}
	return rnd;
}