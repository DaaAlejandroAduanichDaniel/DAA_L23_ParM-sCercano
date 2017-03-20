#include "plane.h"

plane::plane(unsigned density, unsigned width, unsigned height) {
  std::srand(time(NULL));
  for (unsigned i = 0; i < density + 1; i++) {
    content.push_back(new point(
      ((double) rand()) / (double) RAND_MAX * width,
      ((double) rand()) / (double) RAND_MAX * height
    ));
  }
}

bool plane::validDensity(unsigned density) {
  return density > MIN_DENSITY && density < MAX_DENSITY;
}

bool plane::validHeight(unsigned height) {
  return height > 0;
}

bool plane::validWidth(unsigned width) {
  return width > 0;
}

double plane::distBetween (point* A, point* B) {
  return sqrt(pow(fabs(A->getX() - B->getX()), 2) + pow(fabs(A->getY() - B->getY()), 2));
}

std::vector <point*> plane::getContentOrderedX () {
  std::vector <point*> aux = content;
  std::sort (aux.begin(), aux.end(), [] (point* a, point* b) {
    return a->getX() < b->getX();
  });

  return aux;
}

std::vector <point*> plane::getContentOrderedY () {

  std::vector <point*> aux = content;
  std::sort (aux.begin(), aux.end(), [] (point* a, point* b) {
    return a->getY() < b->getY();
  });

  return aux;
}
