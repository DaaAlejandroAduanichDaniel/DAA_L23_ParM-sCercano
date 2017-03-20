#ifndef DIVIDE_H
#define DIVIDE_H

#include "algorithm.h"
#include "brute.h"

class divide : public algorithm {
private:
  solution solver (std::vector<point*>& xPoints, std::vector<point*>& yPoints);
public:
  divide();
  solution operator() (plane& space);
};

#endif // DIVIDE_H
