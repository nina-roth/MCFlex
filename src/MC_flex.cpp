#include "Point.hpp"
#include "RanVec.hpp"
#include "MC_flex.hpp"

#include <iostream>
#include <cmath>

template<typename T>
void MC_integrate<T>::calculate(){
	
	RanVec<T> rands(seed);
	std::vector<Point<T>> values = rands.get_vec_rands(npoints, ndim);
	std::vector<T> weights = get_weights(values, border);
	
	T fexp = T(0);
	T fsq_exp = T(0);

	for(int i=0; i<npoints; i++){

		fexp += weights[i];
		fsq_exp += (weights[i])*(weights[i]);

	}

	T normalisation = T(npoints);
	fexp /= normalisation;
	fsq_exp /= normalisation;

	result_ = volume * fexp;
	error_ = volume * sqrt( (fsq_exp - fexp * fexp )/(normalisation) );

}

template class MC_integrate<double>;
template class MC_integrate<float>;


