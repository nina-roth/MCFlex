#include "Point.hpp"
#include "RanVec.hpp"
#include "MC_flex.hpp"
#include <vector>
#include <stdexcept>
#define BOOST_TEST_MODULE MyTest
#include <boost/test/included/unit_test.hpp>

/*! \file test_pass.cpp 
 *  \brief Test functions that should pass  
 *
 *  Tests a few calculations for approximate floating point equality
 *  and makes sure an exception is thrown if the "borders" vector is nonsensical (0-dimensional).
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


BOOST_AUTO_TEST_CASE( my_test_1 )
{

	std::vector<double> borders(2, 0.5);
    MC_integrate<double> mc1{ 2, 1000, 1., borders, 100, get_weights_square }; //initialise points, volume, border, seed, weight_function
	mc1.calculate();
	double diff_result_1 = fabs(mc1.result() -0.258);
	double diff_error_1 = fabs(mc1.error() -0.013836);

	BOOST_REQUIRE( diff_result_1 < 1e-7 );
    BOOST_REQUIRE( diff_error_1 < 1e-7 );

}

BOOST_AUTO_TEST_CASE( my_test_2 )
{

	std::vector<double> borders(2, 0.5);
	MC_integrate<double> mc2{ 2, 1000, 1., borders, 100, get_weights_circ }; //initialise points, volume, border, seed, weight_function
	mc2.calculate();
	double diff_result_2 = fabs(mc2.result() - 0.194);
	double diff_error_2 = fabs(mc2.error() - 0.0125046);

	BOOST_REQUIRE( diff_result_2 < 1e-7 );
    BOOST_REQUIRE( diff_error_2 < 1e-7 );

}

BOOST_AUTO_TEST_CASE( my_test_3 )
{

	std::vector<double> borders(0, 0);
	BOOST_CHECK_THROW( MC_integrate<double> mc3( 2, 1000, 1., borders, 100, get_weights_circ ), std::runtime_error );

}

// BOOST_AUTO_TEST_CASE_EXPECTED_FAILURES( my_test_4, 1 )
// BOOST_AUTO_TEST_CASE( my_test_4 )
// {

// 	std::vector<double> borders(1, 0.5);
// 	BOOST_CHECK_NO_THROW( MC_integrate mc4(2, 1000, 1., borders, 100, get_weights_circ) );

// }





