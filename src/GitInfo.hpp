#ifndef __GITINFO_H
#define __GITINFO_H
#include <iostream>

/*! \fn header 
 * \brief Version header  
 *
 *  Displays the git commit used at compile time and if some files have been modified wrt to that.
 */

void header(std::ostream &outf);

#endif