/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2021-2022
 *
 * @author Adal Díaz Fariña
 * @since Mar 4 2022
 * @desc Program memory
 *	    This file contain the definitions of MemoryProgram methods
 */

#include "../include/memory_program.h"

// Default constructor
MemoryProgram::MemoryProgram() {
  _pointer = 0;
}

/**
* @brief Construct a new Memory Program object
* @param instructions The list of the instructions
*/
MemoryProgram::MemoryProgram(std::vector<Instruction*> instructions) {
  _pointer = 0;
  _instructions = instructions;
}

// Destructor
MemoryProgram::~MemoryProgram() {
  _instructions.clear();
}

/**
* @brief Get the Next Instruction object
* @return [Instruction] 
*/
Instruction* MemoryProgram::GetNextInstruction() {
  return _instructions[_pointer];
}