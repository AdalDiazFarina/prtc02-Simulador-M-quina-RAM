/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2021-2022
 *
 * @author Adal Díaz Fariña
 * @since Mar 4 2022
 * @desc Output unit
 *			 This file contain the declaration of OutputUnit class methods
 */

#include "../include/output_unit.h"

// Default constructor
OutputUnit::OutputUnit() {}

// Constructor
OutputUnit::OutputUnit(std::string output_file) {
  _output_file = output_file;
  Tape();
}

// Destructor
OutputUnit::~OutputUnit() {}

/**
* @brief This method insert one value in the output tape
* @param value 
*/
void OutputUnit::Write(int value) {
  _tape.push_back(value);
  ++_pos;
}

/**
* @brief This method write the output tape in a file
*/
void OutputUnit::WriteInFile() {
  std::ofstream output;
  output.open(_output_file);
  for (int value : _tape) {
    output << value << "\n";
  }
}