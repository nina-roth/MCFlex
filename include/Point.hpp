#ifndef __POINT_HPP
#define __POINT_HPP
#include <vector>

/*! \file Point.cpp */

/*! \class Point
 *  \brief A Point class   
 *
 *  UNDER CONSTRUCTION: Implements a "Point" of any dimension (default: 2).
 */ 

template<typename T>
class Point{

	public:
		Point (const int dim_=2) : dim(dim_){};
		std::vector<T> coords; /*!< Coordinate vector */
		const int dim; /*!< Point dimension (default: 2) */
		//void set_dummy(T dummy);
		~Point(){};

	private:
		//T dummy;
		
		
};

#endif

