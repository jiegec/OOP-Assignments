#include "review_assigner.h"
#include <fstream>
#include <iostream>

using namespace std;

void ReviewAssigner::load(const char* file) {
  ifstream fp(file);
  cout << "Reading from file " << file << endl;
  string temp_studentno, temp_email;
  fp >> temp_studentno >> temp_email;

  while (!fp.eof()) {
    string studentno, email;
    fp >> studentno >> email;
    if (studentno.length() != 0) {
      contact[studentno] = email;
      reviewers[studentno] = array<string, reviewer_per_stu>();
    }
  }

  cout << "Got " << contact.size() << " student entries" << endl;
}

void ReviewAssigner::choose() {
  for (auto it = contact.begin(); it != contact.end(); ++it) {
    string studentno = it->first;
    if (contact.size() > reviewer_per_stu + 1) {
      // Do a resevoir sampling
      int n = 0;
      int current = 0;
      int end = reviewer_per_stu;
      auto& current_reviewer = reviewers[studentno];
      for (auto it2 = contact.begin(); it2 != contact.end(); ++it2) {
        if (it2->first != studentno) {
          n++;
          if (current >= end) {
            int x = rand() % n;
            if (x < reviewer_per_stu) {
              current_reviewer[x] = it2->first;
            }
          } else {
            current_reviewer[current++] = it2->first;
          }
        }
      }
    }
  }
  cout << "Chose " << contact.size() << " students' reviewers" << endl;
}

void ReviewAssigner::output(const char* file) {
  ofstream fp(file);
  fp << "StudentNo.\tEmail\tReviewer1StuNo.\tReviewer2StuNo.\tReviewer3StuNo." << endl;
  for (auto it = contact.begin(); it != contact.end(); ++it) {
    auto studentno = it->first;
    auto reviewer = reviewers[studentno];
    fp << studentno << " " << it->second;
    for (auto i = 0; i < reviewer_per_stu; i++) {
      fp << " " << reviewer[i];
    }
    fp << endl;
  }
  cout << "Written to file " << file << endl;
}