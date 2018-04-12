#ifndef __MATRIX_H__
#define __MATRIX_H__

class Matrix {
private:
  int row;
  int column;
  int **arr;

public:
  Matrix(const char *file);
  Matrix();

  void load(const char *file);
  void display() const;
  Matrix multiply(const Matrix &another) const;
  void save(const char *file) const;

  ~Matrix();
};

#endif
