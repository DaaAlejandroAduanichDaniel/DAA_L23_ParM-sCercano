#ifndef DIVIDE_H
#define DIVIDE_H

#include "algorithm.h"
#include "brute.h"

class divide : public algorithm {
public:
  solution solver (std::vector<point*>& xPoints, std::vector<point*>::iterator begin, std::vector<point*>::iterator end);
  divide();
  solution operator() (plane& space);
};

#endif // DIVIDE_H
