#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <limits>

#include "plane.h"

struct solution {
  point A;
  point B;
  double distance;
};

class algorithm {
public:
  algorithm();
  virtual solution operator() (std::set<point*>& points) = 0;
};


#endif // ALGORITHM_H
