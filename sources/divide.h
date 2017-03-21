#ifndef DIVIDE_H
#define DIVIDE_H

#include "algorithm.h"
#include "brute.h"

class divide : public algorithm {
public:
  solution solver (std::vector<point*>& xPoints);
  divide();
  solution operator() (plane& space);
};

#endif // DIVIDE_H
