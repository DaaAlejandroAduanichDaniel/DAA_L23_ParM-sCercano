
#include <iostream>
#include <fstream>
#include <vector>
#include <exception>
#include <stdlib.h>
#include <chrono>
#include <string>

#include "../brute.h"
#include "../divide.h"

#define N_ARGS 5
#define USAGE "./tests <width> <height> <density> <size> <meta> \n\n -width:   [1, inf)\n -height:  [1, inf)\n -density: [3, 100]\n -size: number of tests\n -meta: number of times to recreate each test in order to determinate the variability"
#define ERROR_N_ARGS "Error en el número de argumentos"
#define ERROR_T_ARGS "Error en el tipo de argumentos"
#define LOG_FILE "closest.log"

// Meta analysis
struct metaInfo {
  double best;
  double mid;
  double worst;
};

void writeLogMeta (std::vector<metaInfo>& timeBrute, std::vector<metaInfo>& timeDivide) {
  unsigned size = timeDivide.size();
  std::ofstream file;
  file.open(LOG_FILE);
  for (unsigned i = 0; i < size; i++) {
    file << i << "," << timeBrute[i].best << "," << timeBrute[i].mid << "," << timeBrute[i].worst << ","
                     << timeDivide[i].best << "," << timeDivide[i].mid << "," << timeDivide[i].worst << std::endl;
  }
  file.close();
}

void writeLog (std::vector<metaInfo>& timeBrute, std::vector<metaInfo>& timeDivide) {
  unsigned size = timeDivide.size();
  std::ofstream file;
  file.open(LOG_FILE);
  for (unsigned i = 0; i < size; i++) {
    file << i << "," << timeBrute[i].best << "," << timeDivide[i].best << std::endl;
  }
  file.close();
}

void testBattery (unsigned w, unsigned h, unsigned d, unsigned size, unsigned meta) {
  std::vector<metaInfo> timeBrute(size);
  std::vector<metaInfo> timeDivide(size);
  brute bruteSolver;
  divide divideSolver;
  solution a;
  solution b;    
  metaInfo brute;
  metaInfo divide;
  for (unsigned i = 0; i < size; i++) {
    plane space (d * i + 1, w, h);
    // Brute
    brute.best = std::numeric_limits<double>::max();
    brute.worst = 0;
    brute.mid = 0;
    for (unsigned j = 0; j < meta; j++) {
      auto begin = std::chrono::high_resolution_clock::now();
      a = bruteSolver.solver (space.getContent(), space.getContent().begin(), space.getContent().end());
      auto end = std::chrono::high_resolution_clock::now();
      double time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
      if (time < brute.best)
        brute.best = time;
      if (time > brute.worst)
        brute.worst = time;
      brute.mid += time;
    }
    brute.mid /= meta;
    // Divide
    divide.best = std::numeric_limits<double>::max();
    divide.worst = 0;
    divide.mid = 0;
    for (unsigned j = 0; j < meta; j++) {
      auto left = space.getContentOrderedX();
      auto begin = std::chrono::high_resolution_clock::now();
      b = divideSolver.solver(left, left.begin(), left.end());
      auto end = std::chrono::high_resolution_clock::now();
      double time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
      if (time < divide.best)
        divide.best = time;
      if (time > divide.worst)
        divide.worst = time;
      divide.mid += time;
    }
    divide.mid /= meta;
    if (a.distance != b.distance) {
      std::cout << "No se está calculando bien (" << i <<") : " << a.distance << " " << b.distance << std::endl;
      return;
    } else {
      timeBrute[i] = brute;
      timeDivide[i] = divide;
    }
  }
  if (meta > 1)
    writeLogMeta(timeBrute, timeDivide);
  else
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
    unsigned m = std::stoi(argv[5]);
    if (!plane::validDensity(d))
      return error();
    if (!plane::validHeight(h))
      return error();
    if (!plane::validWidth(w))
      return error();
    testBattery(w, h, d, s, m);
  }
}

