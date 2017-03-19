#include "brute.h"

brute::brute() {}

solution brute::operator() (plane& p) {
  std::pair <point*, point*> candidates;
  double min = std::numeric_limits<double>::max();
  double dist;
  std::set<point*> space = p.getContent();
  for (auto iti = space.begin(); iti != std::prev(space.end(), 1); iti++) {
    for (auto itj = std::next(iti, 1) ; itj != space.end(); itj++) {
      dist = p.distBetween(*iti, *itj);
      if (dist < min) {
        min = dist;
        candidates = {*iti, *itj};
      }
    }
  }
  return {*candidates.first, *candidates.second, min};
}


