#ifndef __POINT_HPP
#define __POINT_HPP
#include <vector>

/*! \file Point.cpp */

/*! \class Point
 *  \brief A Point class   
 *
 *  UNDER CONSTRUCTION: Implements a "Point" of any dimension (default: 2).
 */ 
class Point{

	public:
		Point (const int dim_=2) : dim(dim_){};
		std::vector<double> coords; /*!< Coordinate vector */
		const int dim; /*!< Point dimension (default: 2) */
		~Point(){};

	private:
		
		
};

#endif

