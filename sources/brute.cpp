#include "brute.h"

brute::brute() {}

solution brute::operator() (std::vector<point*>& points) {
  std::pair <point*, point*> candidates;
  double min = std::numeric_limits<double>::max();
  double dist;
  for (auto iti = points.begin(); iti != std::prev(points.end(), 1); iti++) {
    for (auto itj = std::next(iti, 1) ; itj != points.end(); itj++) {
      dist = plane::distBetween(*iti, *itj);
      if (dist < min) {
        min = dist;
        candidates = {*iti, *itj};
      }
    }
  }
  return {*candidates.first, *candidates.second, min};
}


