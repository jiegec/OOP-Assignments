#include <cstring>  // strlen , strcpy
#include <iostream> // cout, endl
using namespace std;
class bug {
  char *data_;

public:
  bug(const char *str) {
    data_ = new char[strlen(str) + 1];
    strcpy(data_, str);
  }
  bug(const bug &other) {
    data_ = new char[strlen(other.data_) + 1];
    strcpy(data_, other.data_);
  }
  bug &operator=(const bug &other) {
    if (this == &other)
        return *this;
    delete[] data_;
    data_ = new char[strlen(other.data_) + 1];
    strcpy(data_, other.data_);
    return *this;
  }
  ~bug() { delete [] data_; }
  void show() { cout << data_ << endl; }
};
void test(bug str1) {
  str1.show();
  bug str2("tsinghua");
  str2.show();
  str2 = str1;
  str2.show();
}
int main() {
  bug str1("2011");
  str1.show();
  test(str1);
  str1.show();
  return 0;
}
