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
protected:

public:
  algorithm();
  virtual solution operator() (plane& points) = 0;
};


#endif // ALGORITHM_H
