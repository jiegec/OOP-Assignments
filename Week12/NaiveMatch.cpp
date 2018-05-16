#include <fstream>
#include <iostream>
#include <cstdlib>
#include "NaiveMatch.h"
using namespace std;

void NaiveMatch::loadInput(string fileName, vector<int> &targetLib)
{
    targetLib.clear();
    ifstream fileIn(fileName.c_str());
    if (!fileIn)
    {
        cerr << "Error opening " << fileName << endl;
        exit(-1);
    }
    int val;
    while(fileIn >> val)
    {
        targetLib.push_back(val);
    }
    fileIn.close();

    cout << "Loaded data from file " << fileName << endl;
    for (unsigned i = 0; i < targetLib.size(); ++ i)
    {
        cout << " " << targetLib[i];
    }
    cout << endl;
}

NaiveMatch::NaiveMatch(string patFileName, string inputFileName)
{
    loadInput(patFileName, pattern_);
    loadInput(inputFileName, array_);
}

std::vector<int> NaiveMatch::all_matches() {
    std::vector<int> matches;
    int arrLen = array_.size();
    int patLen = pattern_.size();
    for (int i = 0;i <= arrLen - patLen;i++) {
        bool flag = true;
        for (int j = 0;j < patLen;j++) {
            if (array_[i+j] != pattern_[j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            matches.push_back(i);
        }
    }

    return matches;
}