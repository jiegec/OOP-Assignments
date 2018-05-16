#ifndef __PUBLIC_INHERITANCE_MATCH_H__
#define __PUBLIC_INHERITANCE_MATCH_H__

#include "KMP.h"
#include <string>
#include <vector>

class PublicInheritanceMatch : public KMP {
public:
  PublicInheritanceMatch(std::string patFileName, std::string inputFileName);
  std::vector<int> all_matches();
};

#endif