#include <iostream>
#include <cmath>
#include <gsl/gsl_rng.h> //link -lgsl and -lgslcblas at the very end
#include <vector>
#include <functional>
#include "Point.hpp"

#ifndef GIT_MODIFIED
	#define GIT_MODIFIED "gm"
#endif

#ifndef GIT_VERSION
	#define GIT_VERSION "git version"
#endif

/*! \brief A class to generate vectors of random numbers   
 *
 *  Detailed description TODO.
 */
class Ran{

  	public:
		Ran (unsigned long int seed=0) : generator(NULL) {

			const gsl_rng_type* T;
			T = gsl_rng_ranlxd2;
			generator = gsl_rng_alloc (T);
			gsl_rng_set(generator, seed);
			//std::cout << "Seed is " << seed << std::endl;

		}
		double get_rand();
		std::vector<double> get_rands(long unsigned int);
		std::vector<Point> get_vec_rands(long unsigned int, int);
		~Ran(){gsl_rng_free(generator);}

  	private:
		gsl_rng* generator;

};

std::vector<Point> Ran::get_vec_rands(long unsigned int n, int dim){
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

double Ran::get_rand(){

	return gsl_rng_uniform(this->generator);
}

std::vector<double> Ran::get_rands(long unsigned int n){
	std::vector<double> rnd(n);
	for(long unsigned int i=0;i<n;i++){
	 	rnd[i]=gsl_rng_uniform(this->generator);
	}
	return rnd;
}

/*! \brief A class to do Monte-Carlo Integration of user-defined functions    
 *
 *  Detailed description TODO.
 */
class MC_integrate{

	public:
		MC_integrate(int dim, unsigned long int n, double vol, std::vector<double> b,
					 unsigned long int s=0){//NB: parameters with default values can only be at the end
			ndim=dim;
			npoints=n;
			volume=vol;
			border=b;
			seed=s;
			//std::cout << "Initialised to " << npoints << " " << volume << " " << border << " "<<seed <<std::endl;
		}
		MC_integrate(int dim, unsigned long int n, double vol, std::vector<double> b, unsigned long int s, 
					 std::vector<double> (*weight_function)(std::vector<Point>, std::vector<double>) ){
			ndim=dim;
			npoints=n;
			volume=vol;
			border=b;
			seed=s;
			get_weights=weight_function;
			//std::cout << "Initialised to " << npoints << " " << volume << " " << border << " "<<seed <<std::endl;
		}
		std::vector<double> (*get_weights)(std::vector<Point>, std::vector<double>);
		void calculate();
		void set_values(long unsigned int, double, std::vector<double>, long unsigned int);
		int get_values();
		double result;
		double error;
		~MC_integrate(){};

	private:
		int ndim;
		unsigned long int npoints;
		double  volume;
		unsigned long int seed;
		std::vector<double> border;

};


void MC_integrate::calculate(){
	
	unsigned long int npoints=this->npoints;
	double doub_npoints=double(npoints);

	double volume=this->volume;
	int dim=this->ndim;

	Ran rands(this->seed);
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

std::vector<double> get_weights1(std::vector<double> points, std::vector<double> border){

	std::vector<double> weights;
	std::vector<double>::const_iterator i;
	for(i=points.begin(); i!=points.end(); i++){

		if( (*i)<border[0] ){weights.push_back(1.);}
		else{weights.push_back(0.);}

	}

	return weights;
}

std::vector<double> get_weights_square(std::vector<Point> points, std::vector<double> border){

	bool tester=1;
	double fraction=1.;
	int dim=points[0].dim;
	std::vector<double> weights;
	std::vector<Point>::const_iterator i;
	for(i=points.begin(); i!=points.end(); i++){
		tester=1;
		for(int j=0; j<dim; j++){
			tester = tester && (*i).coords.at(j)<border[j];
		}
		weights.push_back(tester*fraction);
	}

	return weights;
}

std::vector<double> get_weights_circ(std::vector<Point> points, std::vector<double> border){

	double fraction=1.;
	int dim=points[0].dim;
	double radius;
	double border_sq=border[0]*border[0];
	std::vector<double> weights;
	std::vector<Point>::const_iterator i;
	for(i=points.begin(); i!=points.end(); i++){
		radius=0.;
		for(int j=0; j<dim; j++){
			radius+=(*i).coords.at(j) * (*i).coords.at(j);
		}
		if(radius < border_sq){weights.push_back(fraction);}
		else{weights.push_back(0.);}
	}

	return weights;
}


void MC_integrate::set_values(long unsigned int n, double v, std::vector<double> b, long unsigned int s){
	npoints=n;
	volume=v;
	border=b;
	seed=s;
	std::cout << "Values set to "<< npoints << ", " << volume <<  ", " << border[0] << ", "<<seed <<std::endl;
}

int MC_integrate::get_values(){

	return 0;
}

/*! \brief Version header  
 *
 *  Displays the code version used and if some files have been modified wrt git.
 */
void header(std::ostream &outf) {
  time_t now = time(0);
  struct tm tstruct;
  char buf[80];
  tstruct = *localtime(&now);
  strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

  outf << "# Compiled " << __DATE__ << " " << __TIME__ << std::endl;
  outf << "# git HEAD:" << GIT_VERSION << std::endl;
  if (sizeof(GIT_MODIFIED) > 1) {
    outf << "# However, the following files are modified:" << std::endl;
    outf << "#  " << GIT_MODIFIED << std::endl;
  }
  outf << "# Runtime: " << buf << std::endl << std::endl;
}

/*! \brief Main function   
 *
 *  Parameters are dim, borders and number of integration points.
 */
int main(int argc, char *argv[]){


	if(argc != 4){std::cerr << "Error " << std::endl; return -1; }

	header(std::cout);

	int dim=atoi(argv[1]); //!< the dimension of integration
	std::vector<double> borders(dim, atof(argv[2])); //!< the integration borders
	double volume=1.;

	MC_integrate mc1(dim, atoi(argv[3]), volume, borders, 100, get_weights_square); //initialise points, volume, border, seed
	mc1.calculate();
	std::cout << "Result: " << mc1.result << ", +- " << mc1.error<< std::endl;
	
	// Ran rands;
	// for(int i=0;i<10;i++){
	// 	std::cout << rands.get_rand() << std::endl;
	// }
	//rands.~Ran();

	Ran test;
	std::vector<Point> pp;//(5, Point(dim));
	pp=test.get_vec_rands(5,dim);
	//std::cout << std::endl;


	MC_integrate mc2(dim, atoi(argv[3]), volume, borders, 100, get_weights_circ); //initialise points, volume, border, seed
	mc2.calculate();
	std::cout << "Result: " << mc2.result << ", +- " << mc2.error<< std::endl;

	// std::vector<Point>::const_iterator pi;
	// int counter =0;
	// for(pi=pp.begin(); pi!=pp.end(); pi++){
	// 	std::cout << counter << ":" << std::endl;
	// 	for(int j=0; j<dim;j++){
	// 		std::cout << (*pi).coords.at(j) << std::endl;
	// 	}
	// 	counter+=1;
	// }

	//mc1.set_values(1000,1.,0.5,100);
	//mc1.calculate(); //sets border
	//std::cout << mc1.result << " " << mc1.error<< std::endl;

	return 0;
}