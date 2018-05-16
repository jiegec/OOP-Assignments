#ifndef __PRIVATE_COMPOSITION_MATCH_H__
#define __PRIVATE_COMPOSITION_MATCH_H__

#include "KMP.h"
#include <string>

class PrivateCompositionMatch {
public:
  PrivateCompositionMatch(std::string patFileName, std::string inputFileName);
  int matchAndAdvance();

private:
  KMP kmp;
  int currentStart;
};

#endif