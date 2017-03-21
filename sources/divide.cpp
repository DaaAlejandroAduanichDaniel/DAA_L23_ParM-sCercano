#include "divide.h"

divide::divide() {}

solution divide::operator() (plane& space) {
  auto left = space.getContentOrderedX();
  //auto right = space.getContentOrderedY();
  return solver (left);
}

solution divide::solver (std::vector<point*>& xPoints) {
  std::pair <point*, point*> candidates;
  solution dlrmin;                            // par mínimo
  solution closest;
  brute br;
  // solución trivial, usar fuerza bruta
  if (xPoints.size() <= 3) {
    return br.solver (xPoints);    
  } else {
    std::vector <point*> xL;
    std::vector <point*> xR;    

    // seleccionar punto medio
    std::vector <point*>::iterator middleX = xPoints.begin() + (xPoints.size() / 2);
    double xm = (*middleX)->getX();

    // dividir en dos subvectores en función de la x
    std::copy (xPoints.begin(), middleX, std::inserter(xL, xL.begin()));
    std::copy (middleX, xPoints.end(), std::inserter(xR, xR.begin()));

    // resolver recursivamente para los dos subcasos
    solution p1 = solver (xL);
    solution p2 = solver (xR);

    // Elegir la mejor distancia mínima de entre los dos subcasos
    if (p1.distance < p2.distance)
      dlrmin = p1;
    else
      dlrmin = p2;

    // Insertar en yS aquellos elementos de xPoints que cumplen |p - xm | < dlrmin

    std::vector<point*> candidates_l;
    std::vector<point*> candidates_r;

    std::vector<point*> yS;

    // encontrar los puntos dentro del rectángulo
    auto i = xR.begin();
    while (i < xR.end() && fabs((*i)->getX() - xm) < dlrmin.distance) {
      yS.push_back(*i);
      i++;
    }

    i = std::prev(xL.end(),1);
    while (i >= xL.begin() && fabs((*i)->getX() - xm) < dlrmin.distance) {
      yS.push_back(*i);
      i--;
    }

    unsigned nS = xPoints.size();
    closest = dlrmin;

    // Combinar las soluciones    
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
