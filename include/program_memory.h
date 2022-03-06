/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2021-2022
 *
 * @author Adal Díaz Fariña
 * @since Mar 4 2022
 * @desc Memory Program
 *			 This file contain the declaration of ProgramMemory methods
 */

#pragma once
#include <iostream>
#include "instruction.h"
#include <vector>

/**
 * @brief This class is in charge of have the list of instructions and return the instruction that we need in each moment
 * @param _pointer [int] This parameter allow us to know how is the following instruction
 * @param _instruction [vector<Instruction>] The list of the instructions
 */
class ProgramMemory {
  private:
    int _pointer;
    std::vector<Instruction*> _instructions;
  public:
    // Default constructor
    ProgramMemory();
    /**
     * @brief Construct a new Memory Program object
     * @param instructions The list of the instructions
     */
    ProgramMemory(std::vector<Instruction*> instructions);
    // Destructor
    ~ProgramMemory();
    /**
     * @brief Get the Next Instruction object
     * @return [Instruction] 
     */
    Instruction* GetNextInstruction();
};