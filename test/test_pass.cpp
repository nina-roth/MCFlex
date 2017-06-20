#include "../src/Point.hpp"
#include "../src/RanVec.hpp"
#include "../src/MC_flex.hpp"
#include <vector>
#include <stdexcept>
#include <iostream>
#define BOOST_TEST_MODULE MyTest
#include <boost/test/included/unit_test.hpp>

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


BOOST_AUTO_TEST_CASE( my_test_1 )
{

	std::vector<double> borders(2, 0.5);
    MC_integrate mc1(2, 1000, 1., borders, 100, get_weights_square); //initialise points, volume, border, seed, weight_function
	mc1.calculate();
	double diff_result_1 = fabs(mc1.result -0.258);
	double diff_error_1 = fabs(mc1.error -0.013836);

	BOOST_REQUIRE( diff_result_1 < 1e-7 );
    BOOST_REQUIRE( diff_error_1 < 1e-7 );

}

BOOST_AUTO_TEST_CASE( my_test_2 )
{

	std::vector<double> borders(2, 0.5);
	MC_integrate mc2(2, 1000, 1., borders, 100, get_weights_circ); //initialise points, volume, border, seed, weight_function
	mc2.calculate();
	double diff_result_2 = fabs(mc2.result - 0.194);
	double diff_error_2 = fabs(mc2.error - 0.0125046);

	BOOST_REQUIRE( diff_result_2 < 1e-7 );
    BOOST_REQUIRE( diff_error_2 < 1e-7 );

}

BOOST_AUTO_TEST_CASE( my_test_3 )
{

	std::vector<double> borders(0, 0);
	BOOST_CHECK_THROW( MC_integrate mc3(2, 1000, 1., borders, 100, get_weights_circ), std::runtime_error );

}

// BOOST_AUTO_TEST_CASE_EXPECTED_FAILURES( my_test_4, 1 )
// BOOST_AUTO_TEST_CASE( my_test_4 )
// {

// 	std::vector<double> borders(1, 0.5);
// 	BOOST_CHECK_NO_THROW( MC_integrate mc4(2, 1000, 1., borders, 100, get_weights_circ) );

// }





