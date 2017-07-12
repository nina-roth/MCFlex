#ifndef __GITINFO_H
#define __GITINFO_H

#include <iosfwd>

/*! \fn GitHeader 
 * \brief Version GitHeader  
 *
 *  Displays the git commit used at compile time and if some files have been modified wrt to that.
 */

void GitHeader(std::ostream &outf);

#endif