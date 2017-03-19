#ifndef PLANE_H
#define PLANE_H

#include <set>

#include "point.h"

class plane {
private:
  std::set <point*> content;
public:
  plane(unsigned density);

  static bool validDensity (unsigned density);
};

#endif // PLANE_H
