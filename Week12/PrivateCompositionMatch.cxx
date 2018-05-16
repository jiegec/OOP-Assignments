#include "PrivateCompositionMatch.h"

PrivateCompositionMatch::PrivateCompositionMatch(std::string patFileName,
                                                 std::string inputFileName)
    : kmp(patFileName, inputFileName) {
  currentStart = 0;
}

int PrivateCompositionMatch::matchAndAdvance() {
  int result = kmp.match(currentStart);
  currentStart = result + 1;
  return result;
}