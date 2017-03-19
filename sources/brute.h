#ifndef BRUTE_H
#define BRUTE_H

#include "algorithm.h"

class brute : public algorithm {
public:
  brute();
  solution operator() (std::set<point*>& points);
};

#endif // BRUTE_H
