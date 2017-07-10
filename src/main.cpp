#include "Point.hpp"
#include "MC_flex.hpp"
#include "GitInfo.hpp"
//#include "RanVec.hpp" only needed if we explicitely create an instance of class RanVec
#include <iostream>
#include <cmath>
#include <vector>
#include <functional>
#include <stdlib.h>
#include <random>

/*! \file main.cpp */


/*! \fn get_weights_square
 * \brief A weight function to integrate a square area   
 *
 *  TODO Detailed description
 */
template<typename T>
std::vector<T> get_weights_square(std::vector<Point<T>> points, std::vector<T> border){

	bool tester=1;
	T fraction=1.;
	int dim=points[0].dim;
	std::vector<T> weights;
	typename std::vector<Point<T>>::const_iterator i;
	for(i=points.begin(); i!=points.end(); i++){
		tester=1;
		for(int j=0; j<dim; j++){
			tester = tester && (*i).coords.at(j)<border[j];
		}
		weights.push_back(tester*fraction);
	}

	return weights;
}


/*! \fn get_weights_circ
 * \brief A weight function to integrate a circular area  
 *
 *  TODO Detailed description
 */
template<typename T>
std::vector<T> get_weights_circ(std::vector<Point<T>> points, std::vector<T> border){

	T fraction= T(1);
	int dim=points[0].dim;
	T radius;
	T border_sq=border[0]*border[0];
	std::vector<T> weights;
	typename std::vector<Point<T>>::const_iterator i;
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


/*! \fn main 
 * \brief The main function    
 *
 *  Shows how to initialise the integrator and generate results with different weight-functions.
 */
int main(int argc, char *argv[]){

	if(argc != 4){std::cerr << "Error " << std::endl; return -1; }

	header(std::cout);

	int dim=atoi(argv[1]); //!< the dimension of integration
	std::vector<double> borders(dim, atof(argv[2])); //!< the integration borders
	double volume=1.;

	MC_integrate<double> mc1{dim, atoi(argv[3]), volume, borders, 100, get_weights_square}; //initialise points, volume, border, seed, weight_function
	mc1.calculate();
	std::cout << "Result: " << mc1.result() << ", +- " << mc1.error() << std::endl;

	MC_integrate<double> mc2{ dim, atoi(argv[3]), volume, borders, 100, get_weights_circ }; //initialise points, volume, border, seed, weight_function
	mc2.calculate();
	std::cout << "Result: " << mc2.result() << ", +- " << mc2.error() << std::endl;

	MC_integrate<double> mc3 = std::move(mc2);
	mc3.calculate();
	std::cout << "Result: " << mc3.result() << ", +- " << mc3.error() << std::endl;

	std::vector<float> borders_f(dim, float(atof(argv[2])) ); //!< the integration borders
	float volume_f=1.;
	MC_integrate<float> mc4{ dim, atoi(argv[3]), volume_f, borders_f, 100, get_weights_circ }; //initialise points, volume, border, seed, weight_function
	mc4.calculate();
	std::cout << "Result: " << mc4.result() << ", +- " << mc4.error() << std::endl;


	return 0;
}


/*! \mainpage A brief description
 *
 * \section intro_sec Introduction
 *
 * This package provides an Monte-Carlo integrator for user-defined functions.
 *
 * \subsection install_sec Installation
 *
 * \subsubsection step1 Step 1: ./configure
 * \subsubsection step2 Step 2: make
 * \subsubsection step3 Step 3: make check (optional)
 * 
 * 
 */





