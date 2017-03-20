#ifndef BRUTE_H
#define BRUTE_H

#include "algorithm.h"

class brute : public algorithm {
public:
  brute();
  solution solver (std::vector<point*>& points);
  solution operator() (plane& space);
};

#endif // BRUTE_H
