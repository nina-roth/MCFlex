#include "RanVec.hpp"

#include <stdexcept>

template<typename T>
using PointVec = std::vector<Point<T>>;

template<typename T>
PointVec<T> RanVec<T>::get_vec_rands(const int n, const int dim){
	
	PointVec<T> rndPoints( n, Point<T>(dim) );
	if( rndPoints.empty() ){
		throw std::runtime_error("MC_integrate: Illegal parameters for RanVec::get_vec_rands(). Aborting...");
	}
	
	for(int i=0; i<n; i++){
	 	for(int j=0; j<dim; j++){
	 		rndPoints[i].coords.push_back( rand_distr(mt_rand) );
	 	}
	}

	return rndPoints;
}

template<typename T>
std::vector<T> RanVec<T>::get_rands(const int n){
	
	std::vector<T> rnd(n);
	if( rnd.empty() ){
		throw std::runtime_error("MC_integrate: Illegal parameters for RanVec::get_rands(). Aborting...");
	}
	
	for(int i=0; i<n; i++){
	 	rnd[i] = rand_distr(mt_rand);
	}
	
	return rnd;
}

template class RanVec<double>;
template class RanVec<float>;
