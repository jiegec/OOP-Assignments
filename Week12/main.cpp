#include "KMP.h"
#include "NaiveMatch.h"
#include "PrivateCompositionMatch.h"
#include "PrivateInheritanceMatch.h"
#include "PublicCompositionMatch.h"
#include "PublicInheritanceMatch.h"
#include <fstream>
#include <iostream>
#include <chrono>


// NOTE: the missing header files and source files need to be implemented for
// compiling the program The KMP lib only finds one match, that code needs to be
// reused to find all the matches

using namespace std;

int main() {
  KMP matcher("pattern.txt", "array.txt");
  int temp;
  cout << matcher.match(15) << endl;
  cout << "======= public composition match =======" << endl;
  {
    vector<int> matches;
    PublicCompositionMatch PubCM("pattern.txt", "array.txt");
    // fill in the code to compute all the matching indexes
    while ((temp = PubCM.matchAndAdvance()) != -1)
      matches.push_back(temp);

    cout << "Match indexes:";
    for (unsigned i = 0; i < matches.size(); ++i) {
      cout << " " << matches[i];
    }
    cout << endl;
  }
  cout << "======= private composition match =======" << endl;
  {
    vector<int> matches;
    PrivateCompositionMatch PrvCM("pattern.txt", "array.txt");
    // fill in the code to compute all the matching indexes
    while ((temp = PrvCM.matchAndAdvance()) != -1)
      matches.push_back(temp);

    cout << "Match indexes:";
    for (unsigned i = 0; i < matches.size(); ++i) {
      cout << " " << matches[i];
    }
    cout << endl;
  }

  cout << "======= public inheritance match ======= " << endl;
  {
    vector<int> matches;
    PublicInheritanceMatch PubIM("pattern.txt", "array.txt");
    // fill in the code to compute all the matching indexes
    matches = PubIM.all_matches();

    cout << "Match indexes:";
    for (unsigned i = 0; i < matches.size(); ++i) {
      cout << " " << matches[i];
    }
    cout << endl;
  }

  cout << "======= private inheritance match =======" << endl;
  {
    vector<int> matches;
    PrivateInheritanceMatch PrvIM("pattern.txt", "array.txt");
    // fill in the code to compute all the matching indexes
    matches = PrvIM.all_matches();

    cout << "Match indexes:";
    for (unsigned i = 0; i < matches.size(); ++i) {
      cout << " " << matches[i];
    }
    cout << endl;
  }

  cout << "======= naive match =======" << endl;
  {
    vector<int> matches;
    NaiveMatch NM("pattern.txt", "array.txt");
    // fill in the code to compute all the matching indexes
    matches = NM.all_matches();

    cout << "Match indexes:";
    for (unsigned i = 0; i < matches.size(); ++i) {
      cout << " " << matches[i];
    }
    cout << endl;
  }

  cout << "======= timing KMP and NaiveMatch =======" << endl;
  {
    // generate random pattern and array
    ofstream pat("pattern_timing.txt");
    for (int i = 0; i < 10; i++) {
      pat << rand() % 2 << ' ';
    }
    pat.close();
    ofstream arr("array_timing.txt");
    for (int i = 0; i < 10000000; i++) {
      arr << rand() % 2 << ' ';
    }
    arr.close();

    int kmp_ms = 0, naivematch_ms = 0;
    {
        vector<int> matches;
        PublicInheritanceMatch PubIM("pattern_timing.txt", "array_timing.txt");

        auto before = std::chrono::high_resolution_clock::now();
        matches = PubIM.all_matches();
        auto after = std::chrono::high_resolution_clock::now();
        kmp_ms = std::chrono::duration_cast<std::chrono::milliseconds>(after - before).count();
    }

    {
        vector<int> matches;
        NaiveMatch NM("pattern_timing.txt", "array_timing.txt");

        auto before = std::chrono::high_resolution_clock::now();
        matches = NM.all_matches();
        auto after = std::chrono::high_resolution_clock::now();
        naivematch_ms = std::chrono::duration_cast<std::chrono::milliseconds>(after - before).count();
    }
    cout << "KMP time: " << kmp_ms << "ms" << endl;
    cout << "NaiveMatch time: " << naivematch_ms << "ms" << endl;
    cout << "Speedup: " << (double)(naivematch_ms - kmp_ms) / naivematch_ms << endl;
  }

  return 0;
}
