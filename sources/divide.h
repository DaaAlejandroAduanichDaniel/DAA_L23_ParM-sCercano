#ifndef DIVIDE_H
#define DIVIDE_H

#include "algorithm.h"
#include "brute.h"

class divide : public algorithm {
public:
  divide();
  solution operator() (std::vector<point*>& xPoints, std::vector<point*>& yPoints);
};

#endif // DIVIDE_H
