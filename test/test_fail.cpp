#include "Point.hpp"
#include "MC_flex.hpp"

#include <vector>

#define BOOST_TEST_MODULE MyTest2
#include <boost/test/included/unit_test.hpp>

/*! \file test_fail.cpp  
 * \brief Test functions that should fail 
 *
 *  Passing in a "borders" vector with different dimension than "dim" should abort.
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

BOOST_AUTO_TEST_CASE( my_test_4 )
{

	std::vector<double> borders(1, 0.5);
	MC_integrate<double> mc4{ 2, 1000, 1., borders, 100, get_weights_circ };

}