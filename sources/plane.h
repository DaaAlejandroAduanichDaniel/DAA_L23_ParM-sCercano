#ifndef PLANE_H
#define PLANE_H

#include <set>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "point.h"

#define MIN_DENSITY 2
#define MAX_DENSITY 101
#define MIN_WIDTH 1
#define MIN_HEIGHT 1

class plane {
private:
  std::set <point*> content;
public:
  plane(unsigned density, unsigned width, unsigned height);
  static bool validDensity (unsigned density);
  static bool validWidth (unsigned width);
  static bool validHeight (unsigned height);
  inline std::set <point*>& getContent () { return content; }
  static double distBetween (point* A, point* B);
};

#endif // PLANE_H
