#include "Point.hpp"
#include "RanVec.hpp"
#include "MC_flex.hpp"
#include <vector>
#include <stdexcept>
#define BOOST_TEST_MODULE MyTest2
#include <boost/test/included/unit_test.hpp>

/*! \file test_fail.cpp  
 * \brief Test functions that should fail 
 *
 *  Passing in a "borders" vector with different dimension than "dim" should abort.
 */

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

BOOST_AUTO_TEST_CASE( my_test_4 )
{

	std::vector<double> borders(1, 0.5);
	MC_integrate mc4(2, 1000, 1., borders, 100, get_weights_circ);

}