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
  solution operator() (std::vector<point*>& points);
};


#endif // ALGORITHM_H
