#include "Point.hpp"
#include "RanVec.hpp"
#include "MC_flex.hpp"

#include <iostream>
#include <cmath>

void MC_integrate::calculate(){
	
	RanVec rands(seed);
	std::vector<Point> values = rands.get_vec_rands(npoints, ndim);
	std::vector<double> weights = get_weights(values, border);
	
	double fexp = 0.;
	double fsq_exp = 0.;

	for(int i=0; i<npoints; i++){

		fexp += weights[i];
		fsq_exp += (weights[i])*(weights[i]);

	}

	double normalisation = double(npoints);
	fexp /= normalisation;
	fsq_exp /= normalisation;

	result_ = volume * fexp;
	error_ = volume * sqrt( (fsq_exp - fexp * fexp )/(normalisation) );

}



