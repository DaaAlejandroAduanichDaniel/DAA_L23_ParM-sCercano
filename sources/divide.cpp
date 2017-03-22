#include "divide.h"

divide::divide() {}

solution divide::operator() (plane& space) {
  auto left = space.getContentOrderedX();  
  return solver (left, left.begin(), left.end());
}

#include <iostream>

solution divide::solver (std::vector<point*>& xPoints, std::vector<point*>::iterator begin, std::vector<point*>::iterator end) {
  std::pair <point*, point*> candidates;
  solution dlrmin;
  solution closest;
  brute br;
  // solución trivial, usar fuerza bruta    
  if (std::distance(begin, end) <= 3) {
    return br.solver (xPoints, begin, end);
  } else {    
    // seleccionar punto medio
    std::vector <point*>::iterator middleX = begin + (std::distance(begin, end) / 2);
    double xm = (*middleX)->getX();

    // dividir en dos subvectores en función de la x y resolver recursivamente para los dos subcasos
    solution p1 = solver (xPoints, begin, middleX);
    solution p2 = solver (xPoints, middleX + 1, end);

    // Elegir la mejor distancia mínima de entre los dos subcasos
    if (p1.distance < p2.distance)
      dlrmin = p1;
    else
      dlrmin = p2;

    // Insertar en yS aquellos elementos de xPoints que cumplen |p - xm | < dlrmin
    std::vector<point*> yS;

    // encontrar los puntos dentro del rectángulo
    auto i = middleX;
    while (i < end && fabs((*i)->getX() - xm) < dlrmin.distance) {
      yS.push_back(*i);
      i++;
    }

    i = std::prev(middleX,1);
    while (i >= begin && fabs((*i)->getX() - xm) < dlrmin.distance) {
      yS.push_back(*i);
      i--;
    }

    unsigned nS = xPoints.size();
    closest = dlrmin;

    // Combinar las soluciones
    //std::cout << yS.size() << std::endl;

    for (auto i = yS.begin(); i != std::prev(yS.end(), 1); i++) {
      auto k = std::next(i, 1);
      while (k != yS.end()) {
        double newDistance = plane::distBetween(*i, *k);
        if (newDistance < closest.distance) {
          closest.A = **i;
          closest.B = **k;
          closest.distance = newDistance;
        }
        std::advance(k, 1);
      }
    }
  }
  return closest;
}
