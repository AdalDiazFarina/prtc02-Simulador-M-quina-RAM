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
#include "../include/control_unit.h"
#include <fstream>

// User guide
void Help() {
  std::cout << "./simulator ram_program.ram input_tape.in output_tape.out\n";
  std::cout << "ram_program: file with the RAM program \n";
  std::cout << "input_tape.in: file with the contents of the input tape \n";
  std::cout << "output_tape.out: file with the contents of the output tape \n";
}

// Create a vector with the input unit data
std::vector<int> CreateInputUnitData(std::string file) {
  std::string::size_type sz;
  std::ifstream input;
  std::string line;
  std::vector<int> input_data;
  input.open(file);
  if (input.is_open()) {
    while(!input.eof()) {
      getline(input, line);
      input_data.push_back(stoi(line, &sz));
    }
  } else {
    throw "Error. The file can`t be opened";
  }
  return input_data;
}

// Main program
int main(int argc, char *argv[]) {
  if (argc == 1) Help();
  if (argc == 4) {
    // Program memory

    ReadData read_data(argv[1]);
    ProgramMemory program_memory = read_data.GetProgramMemory();

    // Data memory 
    DataMemory data_memory;

    // Output unit
    OutputUnit output_unit(argv[3]);

    // Input unit
    InputUnit input_unit(CreateInputUnitData(argv[2]));

    // Control unit
    ControlUnit control_unit(input_unit, output_unit, data_memory, program_memory);
    control_unit.Simulation();
  } else {
    std::cout << "Error. Expected: 4, Received: " << argc << "\n";
    return 0;
  }
}