#include "divide.h"

divide::divide() {}

solution divide::operator() (plane& space) {
  auto left = space.getContentOrderedX();
  auto right = space.getContentOrderedY();
  return solver (left, right);
}

solution divide::solver (std::vector<point*>& xPoints, std::vector<point*>& yPoints) {
  std::pair <point*, point*> candidates;
  solution pmin;
  solution closest;
  brute br;
  // solución trivial, usar fuerza bruta
  if (xPoints.size() <= 3) {
    return br.solver (xPoints);    
  } else {
    std::vector <point*> xL;
    std::vector <point*> xR;
    std::vector <point*> yL;
    std::vector <point*> yR;

    // seleccionar punto medio
    std::vector <point*>::iterator middleX = std::next(xPoints.begin(), (xPoints.size() / 2));
    double xm = (*middleX)->getX();

    // dividir en dos subvectores en función de la x

    std::copy (xPoints.begin(), middleX , std::inserter(xL, xL.begin()));
    std::copy (middleX, xPoints.end(), std::inserter(xR, xR.begin()));

    // Copiar al subvector yL aquellos elementos de yPoints cuya x sea menor o igual a la del punto medio
    // Copiar al subvector yR aquellos elementos de yPoints cuya x sea mayor a la del punto medio       

    for (auto i = yPoints.begin(); i != yPoints.end(); i++) {
      if ((*i)->getX() <= xm)
        yL.push_back(*i);
      if ((*i)->getX() > xm)
        yR.push_back(*i);
    }

    // resolver recursivamente para los dos subcasos
    solution p1 = solver (xL, yL);
    solution p2 = solver (xR, yR);

    // Actualizar la distancia mínima con las soluciones obtenidas
    if (p1.distance < p2.distance)
      pmin = p1;
    else
      pmin = p2;

    // Insertar en yS aquellos elementos de yPoints que cumplen |p - xm | < pmin
    std::vector<point*> yS;
    for (auto i = yPoints.begin(); i != yPoints.end(); i++) {
      if (fabs((*i)->getX() - xm) < pmin.distance)
        yS.push_back(*i);
    }
    unsigned nS = yPoints.size();
    closest = pmin;

    // Combinar las soluciones    

    for (auto i = yS.begin(); i != std::prev(yS.end(), 1); ++i) {
      auto k = std::next(i, 1);
      while (k != yS.end() && (*k)->getY() - (*i)->getY() < pmin.distance) {
        double newDistance = plane::distBetween(*i, *k);
        if (newDistance < closest.distance) {
          closest.A = **i;
          closest.B = **k;
          closest.distance = newDistance;
        }
        k = std::next(k, 1);
      }
    }
  }
  return closest;
}
