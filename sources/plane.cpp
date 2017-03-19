#include "plane.h"

plane::plane(unsigned density) {

}

bool plane::validDensity(unsigned density) {
  return density > 0 && density < 100;
}
