#include "PrivateInheritanceMatch.h"

PrivateInheritanceMatch::PrivateInheritanceMatch(std::string patFileName,
                                                 std::string inputFileName)
    : KMP(patFileName, inputFileName) {}

std::vector<int> PrivateInheritanceMatch::all_matches() {
    std::vector<int> matches;
    int temp = 0;
    while ((temp = match(temp)) != -1) {
        matches.push_back(temp);
        temp ++;
    }
    return matches;
}