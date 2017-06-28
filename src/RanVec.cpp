#include "Point.hpp"
#include "RanVec.hpp"
#include <stdexcept>

template<typename T>
RanVec<T>::RanVec (const unsigned long int seed) {

			const gsl_rng_type* gsl_type;
			gsl_type = gsl_rng_ranlxd2;
			generator = gsl_rng_alloc(gsl_type);
			gsl_rng_set(generator, seed);

}

template<typename T>
std::vector<Point<T>> RanVec<T>::get_vec_rands(const int n, const int dim){
	std::vector<Point<T>> rnd(n, Point<T>(dim));
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

template<typename T>
std::vector<T> RanVec<T>::get_rands(const int n){
	std::vector<T> rnd(n);
	if( rnd.empty() ){
		throw std::runtime_error("MC_integrate: Illegal parameters for RanVec::get_rands(). Aborting...");
	}
	for(int i=0; i<n; i++){
	 	rnd[i] = gsl_rng_uniform(generator);
	}
	return rnd;
}


template class RanVec<double>;
template class RanVec<float>;
