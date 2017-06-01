#ifndef __POINT_HPP
#define __POINT_HPP
#include <vector>

/*! \brief A Point class   
 *
 *  Implements a "Point" of any dimension (default: 2).
 */ 
class Point{

	public:
		Point (unsigned int d=2);
		std::vector<double> coords; /*!< Coordinate vector */
		int dim; /*!< Point dimension (default: 2) */
		~Point();

	private:
};

#endif

