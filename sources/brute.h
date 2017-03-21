#ifndef BRUTE_H
#define BRUTE_H

#include "algorithm.h"

class brute : public algorithm {
public:
  brute();
  solution solver (std::vector<point*>& xPoints, std::vector<point*>::iterator begin, std::vector<point*>::iterator end);
  solution operator() (plane& space);
};

#endif // BRUTE_H
