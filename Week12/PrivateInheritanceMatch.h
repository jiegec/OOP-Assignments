#ifndef __PRIVATE_INHERITANCE_MATCH_H__
#define __PRIVATE_INHERITANCE_MATCH_H__

#include "KMP.h"
#include <string>

class PrivateInheritanceMatch : private KMP {
public:
  PrivateInheritanceMatch(std::string patFileName, std::string inputFileName);
  std::vector<int> all_matches();
};

#endif