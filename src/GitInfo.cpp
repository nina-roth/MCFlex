#include "GitInfo.hpp"

#include <ostream>

#ifndef GIT_MODIFIED
	#define GIT_MODIFIED "N/A"
#endif

#ifndef GIT_VERSION
	#define GIT_VERSION "N/A"
#endif

void GitHeader(std::ostream &outf) {
  time_t now = time(0);
  struct tm tstruct;
  char buf[80];
  tstruct = *localtime(&now);
  strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

  outf << "# Compiled " << __DATE__ << " " << __TIME__ << std::endl;
  outf << "# git HEAD:" << GIT_VERSION << std::endl;
  if (sizeof(GIT_MODIFIED) > 1) {
    outf << "# However, the following files are modified:" << std::endl;
    outf << "#  " << GIT_MODIFIED << std::endl;
  }
  outf << "# Runtime: " << buf << std::endl << std::endl;
}