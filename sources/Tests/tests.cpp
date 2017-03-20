
#include <iostream>
#include <fstream>
#include <vector>
#include <exception>
#include <stdlib.h>
#include <chrono>
#include <string>

#include "../brute.h"
#include "../divide.h"

#define N_ARGS 4
#define USAGE "./tests <width> <height> <density> <size> \n\n -width:   [1, inf)\n -height:  [1, inf)\n -density: [3, 100]\n -size: number of tests"
#define ERROR_N_ARGS "Error en el número de argumentos"
#define ERROR_T_ARGS "Error en el tipo de argumentos"
#define LOG_FILE "closest.log"

void writeLog (std::vector<double>& timeBrute, std::vector<double>& timeDivide) {
  unsigned size = timeDivide.size();
  std::ofstream file;
  file.open(LOG_FILE);
  for (unsigned i = 0; i < size; i++) {
    file << i << "," << timeBrute[i] << "," << timeDivide[i] << std::endl;
  }
  file.close();
}


void testBattery (unsigned w, unsigned h, unsigned d, unsigned size) {
  std::vector<double> timeBrute(size);
  std::vector<double> timeDivide(size);
  brute bruteSolver;
  divide divideSolver;
  for (unsigned i = 0; i < size; i++) {
    plane space (d * i + 1, w, h);
    // Brute
    auto begin = std::chrono::high_resolution_clock::now();
    bruteSolver (space);
    auto end = std::chrono::high_resolution_clock::now();
    timeBrute[i] = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count();
    // Divide
    auto left = space.getContentOrderedX();
    auto right = space.getContentOrderedY();
    begin = std::chrono::high_resolution_clock::now();
    divideSolver.solver(left, right);
    end = std::chrono::high_resolution_clock::now();
    timeDivide[i] = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count();
  }
  writeLog(timeBrute, timeDivide);
}

int error () {
  std::cout << ERROR_N_ARGS << std::endl;
  std::cout << USAGE << std::endl;
  return -1;
}

int main(int argc, char *argv[]) {
  if (argc - 1 != N_ARGS) {
    return error();
  } else {
    unsigned w = std::stoi(argv[1]);
    unsigned h = std::stoi(argv[2]);
    unsigned d = std::stoi(argv[3]);
    unsigned s = std::stoi(argv[4]);
    if (!plane::validDensity(d))
      return error();
    if (!plane::validHeight(h))
      return error();
    if (!plane::validWidth(w))
      return error();
    testBattery(w, h, d, s);
  }
}
