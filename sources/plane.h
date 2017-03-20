#ifndef PLANE_H
#define PLANE_H

#include <vector>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <algorithm>

#include "point.h"

#define MIN_DENSITY 2
#define MAX_DENSITY 101
#define MIN_WIDTH 1
#define MIN_HEIGHT 1

class plane {
private:
  std::vector <point*> content;
public:
  plane(unsigned density, unsigned width, unsigned height);
  static bool validDensity (unsigned density);
  static bool validWidth (unsigned width);
  static bool validHeight (unsigned height);
  inline std::vector <point*>& getContent () { return content; }
  static double distBetween (point* A, point* B);
  std::vector <point*> getContentOrderedX ();
  std::vector <point*> getContentOrderedY ();
};

#endif // PLANE_H
