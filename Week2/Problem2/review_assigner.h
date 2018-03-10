#ifndef __REVIEW_ASSIGNER_H__
#define __REVIEW_ASSIGNER_H__

#include <map>
#include <string>
#include <array>

const int reviewer_per_stu = 3;

class ReviewAssigner {
 public:
  void load(const char* file);
  void choose();
  void output(const char* file);

 private:
  std::map<std::string, std::string> contact;
  std::map<std::string, std::array<std::string, reviewer_per_stu> > reviewers;
};

#endif