#ifndef __POINT_HPP
#define __POINT_HPP

#include <vector>

/*! \brief A Point class   
 *
 *  Detailed description TODO.
 */ 
class Point{

	public:
		Point (int d=2) {
			dim=d;
		}
		std::vector<double> coords; /*!< Coordinate vector */
		int dim;
		~Point(){};

	private:
};

#endif