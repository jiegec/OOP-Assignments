#include "PublicInheritanceMatch.h"

PublicInheritanceMatch::PublicInheritanceMatch(std::string patFileName,
                                               std::string inputFileName)
    : KMP(patFileName, inputFileName) {}

std::vector<int> PublicInheritanceMatch::all_matches() {
    std::vector<int> matches;
    int temp = 0;
    while ((temp = match(temp)) != -1) {
        matches.push_back(temp);
        temp ++;
    }
    return matches;
}