#ifndef POINT_H
#define POINT_H


class point {
private:
  double x;
  double y;
public:
  point(double X, double Y);
  inline double getX () { return x; }
  inline double getY () { return y; }
};

#endif // POINT_H
