#include "brute.h"

#include <iostream>

brute::brute() {}

solution brute::solver (std::vector<point*>& xPoints, std::vector<point*>::iterator begin, std::vector<point*>::iterator end) {
  std::pair <point*, point*> candidates;
  double min = std::numeric_limits<double>::max();
  double dist;  
  if (std::distance(begin, end) >= 2) {
    for (auto iti = begin; iti != std::prev(end, 1); iti++) {
      for (auto itj = std::next(iti, 1) ; itj != end; itj++) {
        dist = plane::distBetween(*iti, *itj);
        if (dist < min) {
          min = dist;
          candidates = {*iti, *itj};
        }
      }
    }
    return {*candidates.first, *candidates.second, min};
  } else {
    return {point(), point(), min};
  }
}

solution brute::operator() (plane& space) {
  return solver (space.getContent(), space.getContent().begin(), space.getContent().end());
}


