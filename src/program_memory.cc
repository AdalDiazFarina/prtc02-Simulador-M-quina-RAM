/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2021-2022
 *
 * @author Adal Díaz Fariña
 * @since Mar 4 2022
 * @desc Program memory
 *	    This file contain the definitions of ProgramMemory methods
 */

#include "../include/program_memory.h"

// Default constructor
ProgramMemory::ProgramMemory() {
  _pointer = 0;
}

/**
* @brief Construct a new Memory Program object
* @param instructions The list of the instructions
*/
ProgramMemory::ProgramMemory(std::vector<Instruction*> instructions) {
  _pointer = 0;
  _instructions = instructions;
}

// Destructor
ProgramMemory::~ProgramMemory() {
  _instructions.clear();
}

/**
* @brief Get the Next Instruction object
* @return [Instruction] 
*/
Instruction* ProgramMemory::GetNextInstruction() {
  return _instructions[_pointer];
}