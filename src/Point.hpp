#ifndef __POINT_HPP
#define __POINT_HPP
#include <vector>

/*! \brief A Point class   
 *
 *  UNDER CONSTRUCTION: Implements a "Point" of any dimension (default: 2).
 */ 
class Point{

	public:
		Point (int dim_=2) : dim(dim_){};
		std::vector<double> coords; /*!< Coordinate vector */
		int dim; /*!< Point dimension (default: 2) */
		~Point(){};

	private:
		
		
};

#endif

