#ifndef __POINT_HPP
#define __POINT_HPP

/*! \brief A Point class   
 *
 *  Implements a "Point" of any dimension (default: 2).
 */ 
class Point{

	public:
		Point (int d=2) {
			dim=d;
		}
		std::vector<double> coords; /*!< Coordinate vector */
		int dim; /*!< Point dimension (default: 2) */
		~Point(){};

	private:
};

#endif