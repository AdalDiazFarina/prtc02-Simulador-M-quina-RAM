/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2021-2022
 *
 * @author Adal Díaz Fariña
 * @since Mar 4 2022
 * @desc Control unit
 *			 This file contain the declarations of ControlUnit methods
 */

#pragma once
#include "instruction.h"

/**
 * @brief This class represent the control unit. The control unit is in charge of the simulation of the machine ram
 * @param _input_tape [InputTape] Manage all the input data
 * @param _output_tape [OutputTape] Manage all the output data
 * @param _data_memory [DataMemory] Contain all the registers
 * @param _program_memory [ProgramMemory] Contain the list of the instructions
 */
class ControlUnit {
  private:
    InputUnit _input_unit;
    OutputUnit _output_unit;
    DataMemory _data_memory;
    ProgramMemory _program_memory;
  public:
    // Default constructor
    ControlUnit();
    /**
     * @brief Construct a new Control Unit object
     * 
     * @param input_unit [InputUnit]
     * @param output_unit [OutputUnit]
     * @param data_memory [DataMemory]
     * @param program_memory [ProgramMemory]
     */
    ControlUnit(InputUnit input_unit, OutputUnit output_unit, DataMemory data_memory, ProgramMemory program_memory);
    // Destructor
    ~ControlUnit();

    // This method is in charge of reproduce the simulation of the ram machine
    void Simulation();
};
