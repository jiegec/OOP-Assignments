#include "PublicCompositionMatch.h"

PublicCompositionMatch::PublicCompositionMatch(std::string patFileName,
                                               std::string inputFileName)
    : kmp(patFileName, inputFileName) {
  currentStart = 0;
}

int PublicCompositionMatch::matchAndAdvance() {
    int result = kmp.match(currentStart);
    currentStart = result + 1;
    return result;
}