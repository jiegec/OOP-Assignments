#ifndef __PUBLIC_COMPOSITION_MATCH_H__
#define __PUBLIC_COMPOSITION_MATCH_H__

#include <string>
#include "KMP.h"

class PublicCompositionMatch {
public:
  PublicCompositionMatch(std::string patFileName, std::string inputFileName);
  KMP kmp;
  int currentStart;
  int matchAndAdvance();
};

#endif