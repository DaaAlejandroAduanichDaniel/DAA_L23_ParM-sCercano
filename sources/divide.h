#ifndef DIVIDE_H
#define DIVIDE_H

#include "algorithm.h"

class divide : public algorithm {
public:
  divide();
  solution operator() (plane& p);
};

#endif // DIVIDE_H
