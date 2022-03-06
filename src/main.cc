/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2021-2022
 *
 * @author Adal Díaz Fariña
 * @since Mar 4 2022
 * @desc Main
 *			 This file contain the main program
*/

#include "../include/read_data.h"

// User guide
void Help() {
  std::cout << "./simulator ram_program.ram input_tape.in output_tape.out\n";
  std::cout << "ram_program: file with the RAM program \n";
  std::cout << "input_tape.in: file with the contents of the input tape \n";
  std::cout << "output_tape.out: file with the contents of the output tape \n";
}

// Main program
int main(int argc, char *argv[]) {
  if (argc == 1) Help();
  if (argc == 4) {
    std::cout << tape << std::endl;
    ReadData read_data(argv[1]);
  } else {
    std::cout << "Error. Expected: 4, Received: " << argc << "\n";
    return 0;
  }
}