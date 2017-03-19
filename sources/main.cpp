#include <iostream>
#include <string>

#include "plane.h"
#include "brute.h"

#define USAGE "./closest <width> <height> <density> \n\n -width:   [1, inf)\n -height:  [1, inf)\n -density: [3, 100]"
#define N_ARGS 3

int error () {
  std::cout << USAGE << std::endl;
}

int main(int argc, char *argv[]) {
  if (argc != N_ARGS + 1)
    return error();
  unsigned w = std::stoi(argv[1]);
  unsigned h = std::stoi(argv[2]);
  unsigned d = std::stoi(argv[3]);
  if (!plane::validDensity(d))
    return error();
  if (!plane::validHeight(h))
    return error();
  if (!plane::validWidth(w))
    return error();
  plane space (d, w, h);
  brute br;
  solution s = br (space.getContent());
  std::cout << s.distance << std::endl;
}
