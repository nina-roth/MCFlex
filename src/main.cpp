#include "Point.hpp"
#include "MC_flex.hpp"
#include "GitInfo.hpp"
//#include "RanVec.hpp" only needed if we explicitely create an instance of class RanVec
#include <iostream>
#include <cmath>
#include <vector>
#include <functional>
#include <stdlib.h>


/*! \brief The main function    
 *
 *  Defines a few weight functions and integrates them using MC_flex integrator
 */

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

	MC_integrate mc1(dim, atoi(argv[3]), volume, borders, 100, get_weights_square); //initialise points, volume, border, seed, weight_function
	mc1.calculate();
	std::cout << "Result: " << mc1.result << ", +- " << mc1.error<< std::endl;
	
	// RanVec rands;
	// for(int i=0;i<10;i++){
	// 	std::cout << rands.get_rand() << std::endl;
	// }
	//rands.~RanVec();

	//RanVec test;
	//std::vector<Point> pp;//(5, Point(dim));
	//pp=test.get_vec_rands(5,dim);
	//std::cout << std::endl;


	MC_integrate mc2(dim, atoi(argv[3]), volume, borders, 100, get_weights_circ); //initialise points, volume, border, seed, weight_function
	mc2.calculate();
	std::cout << "Result: " << mc2.result << ", +- " << mc2.error<< std::endl;


	// std::vector<double> bb(3, 15);
	// //std::cout << bb.empty() << std::endl;
	// std::vector<double> bb2(0.2, 15);
	// //std::cout << bb2.empty() << std::endl;
	// //gw = nullptr;
	// //std::vector<double> (*)(std::vector<Point>, std::vector<double>) gw;// = nullptr;
	// try{
	// 	MC_integrate mc3(dim, atoi(argv[3]), volume, bb2, 100, get_weights_circ);
	// }
	// catch(std::exception& e){
	// 	std::cout << e.what() << std::endl;
	// }
	//std::cout << bb.at(0) << std::endl;

	//mc1.set_values(1000,1.,0.5,100);
	//mc1.calculate(); //sets border
	//std::cout << mc1.result << " " << mc1.error<< std::endl;

	return 0;
}