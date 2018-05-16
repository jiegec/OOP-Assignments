#ifndef __NAIVE_MATCH_H__
#define __NAIVE_MATCH_H__

#include <string>
#include <vector>

class NaiveMatch
{
    public:
        NaiveMatch(std::string patFileName, std::string inputFileName);
        std::vector<int> all_matches();
    protected:
        std::vector<int> array_;   // stores the integer (0-1) array
        std::vector<int> pattern_; // stores the integer (0-1) pattern to be searched
        void loadInput(std::string fileName, std::vector<int> &array); // load in the input file
    private:
        NaiveMatch(const NaiveMatch& other);
        NaiveMatch& operator = (const NaiveMatch& other);
};
#endif