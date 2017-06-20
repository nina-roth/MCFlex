#include "Point.hpp"
#include "RanVec.hpp"
#include "MC_flex.hpp"

#include <iostream>
#include <cmath>

// MC_integrate::~MC_integrate(){

// }

void MC_integrate::calculate(){
	
	unsigned long int npoints=this->npoints;
	double doub_npoints=double(npoints);

	double volume=this->volume;
	int dim=this->ndim;

	RanVec rands(this->seed);
	std::vector<Point> values=rands.get_vec_rands(npoints, dim);
	std::vector<double> weights = get_weights(values, this->border);
	double fexp=0.;
	double fsq_exp=0.;
	long unsigned int i;

	for(i=0; i<npoints; i++){

		fexp += weights[i]/doub_npoints;
		fsq_exp += (weights[i])*(weights[i])/doub_npoints;

	}

	this->result=volume * fexp;
	this->error=volume * sqrt((fsq_exp - fexp * fexp ))/sqrt(doub_npoints);

}

// MC_integrate::MC_integrate(int dim, unsigned long int n, double vol, std::vector<double> b,
// 					 unsigned long int s){//NB: parameters with default values can only be at the end
// 			ndim=dim;
// 			npoints=n;
// 			volume=vol;
// 			border=b;
// 			seed=s;
// 			//std::cout << "Initialised to " << npoints << " " << volume << " " << border << " "<<seed <<std::endl;
// }

// MC_integrate::MC_integrate(const int dim, const unsigned long int n,  const double vol, std::vector<double> b, const unsigned long int s, 
// 					 std::vector<double> (*weight_function)(std::vector<Point>, std::vector<double>) ){
// 			ndim=dim;
// 			npoints=n;
// 			volume=vol;
// 			border=b;
// 			seed=s;
// 			get_weights=weight_function;
// 			//std::cout << "Initialised to " << npoints << " " << volume << " " << border << " "<<seed <<std::endl;
// }


// void MC_integrate::set_values(long unsigned int n, double v, std::vector<double> b, long unsigned int s){
// 	npoints=n;
// 	volume=v;
// 	border=b;
// 	seed=s;
// 	std::cout << "Values set to "<< npoints << ", " << volume <<  ", " << border[0] << ", "<<seed <<std::endl;
// }



