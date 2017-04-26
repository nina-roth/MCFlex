#include <iostream>
#include <cmath>
#include <gsl/gsl_rng.h> //link -lgsl and -lgslcblas at the very end

int in_region(double value, double max){

	int weight=0;
	if (value < max) weight=1;

	return weight; 
}


int main(int argc, char *argv[]){
	
	const int npoints=atoi(argv[1]);
	const double doub_npoints=double(npoints);
	int seed=100;
	if (argc > 2){seed=atoi(argv[2]);}// std::cout << "Hello1" <<std::endl;}
	//else {seed=100;}// std::cout << "Hello2" <<std::endl;}
	std::cout << "Seed: "<< seed << std::endl;
	
	double rnd_x,rnd_y;
	//double *rnd_x=new double[npoints];
	//double *rnd_y=new double[npoints];

	gsl_rng *r;
	const gsl_rng_type * T; //generator type variable
    T = gsl_rng_ranlxs2; //this is the name of the generator defined in the environmental variable GSL_RNG_TYPE
    r = gsl_rng_alloc (T); //this allocates memory for the generator with type T
    gsl_rng_set(r,seed); 

    int i;
    double fexp=0., fsq_exp=0.,fexp_rad=0., fsq_exp_rad=0.;
    double volume=1;
    int weight_x, weight_y, weight_rad;

	for(i=0; i<npoints; i++){
		rnd_x=gsl_rng_uniform(r)-0.5;
		rnd_y=gsl_rng_uniform(r)-0.5;
		//radius= sqrt(rnd_x[i] * rnd_x[i] + rnd_y[i] * rnd_y[i]);

		//std::cout << i << " "<< rnd_x << " " << fabs(rnd_x) << std::endl;

		weight_x=in_region(fabs(rnd_x),0.5);
		weight_y=in_region(fabs(rnd_y),0.5);
		fexp += weight_x * weight_y/doub_npoints;
		fsq_exp += (weight_x * weight_y)*(weight_x * weight_y)/doub_npoints;

		weight_rad=in_region(sqrt(rnd_x * rnd_x + rnd_y * rnd_y), 0.5);
		fexp_rad += weight_rad/doub_npoints;
		fsq_exp_rad += (weight_rad)/doub_npoints;

	}



	gsl_rng_free (r); 
	
	double result=volume * fexp;
	double error=volume * sqrt((fsq_exp - fexp * fexp ))/sqrt(doub_npoints);
	if(fabs(fsq_exp/doub_npoints - fexp * fexp/doub_npoints )< 1e-17){error=0.;}

	double result_rad=volume * fexp_rad;
	double error_rad=volume * sqrt((fsq_exp_rad - fexp_rad * fexp_rad )/doub_npoints);
	if(fabs(fsq_exp_rad/doub_npoints - fexp_rad * fexp_rad/doub_npoints )< 1e-17){error_rad=0.;}

	std::cout << "Rectangle: Result for "<< npoints <<" points: "<< result << " +- " << error << std::endl;
	
	std::cout << "Circle: Result for "<< npoints <<" points: "<< result_rad << " +- " << error_rad << std::endl;
	

	return 0;
}