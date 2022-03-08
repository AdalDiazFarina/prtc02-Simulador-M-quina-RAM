/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2021-2022
 *
 * @author Adal Díaz Fariña
 * @since Mar 4 2022
 * @desc Control unit
 *			 This file contain the definitions of ControlUnit methods
 */

#include "../include/control_unit.h"


// Default constructor
ControlUnit::ControlUnit() {}

/**
* @brief Construct a new Control Unit object
* 
* @param input_unit [InputUnit]
* @param output_unit [OutputUnit]
* @param data_memory [DataMemory]
* @param program_memory [ProgramMemory]
*/
ControlUnit::ControlUnit(InputUnit input_unit, OutputUnit output_unit, DataMemory data_memory, ProgramMemory program_memory) {
  _input_unit = input_unit;
  _output_unit = output_unit;
  _data_memory = data_memory;
  _program_memory = program_memory;
}

// Destructor
ControlUnit::~ControlUnit() {}

// This method is in charge of reproduce the simulation of the ram machine
void ControlUnit::Simulation() {
  Instruction* instruction = new Instruction();
  std::string name;
  while(true) {
    instruction = _program_memory.GetNextInstruction();
    name = instruction -> GetOperator();
    instruction -> Run(_data_memory, _input_unit, _output_unit, _program_memory);
    if (name == "halt" || name == "HALT") {
      _output_unit.WriteInFile();
      break;
    }
  }
}
