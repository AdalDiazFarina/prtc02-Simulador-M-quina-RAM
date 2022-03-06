/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2021-2022
 *
 * @author Adal Díaz Fariña
 * @since Mar 4 2022
 * @desc Read the input data
 *			 This file contain the declarations of ReadData methods
 */

#pragma once
#include <iostream>
#include <vector>
#include "program_memory.h"

/**
* @brief ReadData This class read the input files and structure the data according to the program design
* @param _program_memory [ProgramMemory] This class contain all the instruction
*/
class ReadData {
  private:
    ProgramMemory _program_memory;
  public:
    // Default constructor
    ReadData();
    /**
    * @brief Constructor
    * @param ram_program [std::string] name of the file with the ram program
    */
    ReadData(std::string ram_program);
    // Destructor
    ~ReadData();

  private:
    /**
    * @brief This method transform the lines into instructions and save the in 
    * @param data [Array] with all the filtered line
    */
    void LinesToInstruction(std::vector<std::string> data);
    /**
    * @brief This method separate the string whit the delimiter
    * @param str [std::string] string to separate
    * @param delimiter [std::string] delimiter by which the string is separated
    * @return [std::vector<std::string>] Vector of the separate elements
    */
    std::vector<std::string> Split(std::string str, std::string delimiter);
    /**
    * @brief This method transform the split line into a instruction
    * @param instruction [String] split line
    * @return [Instruction] 
    */
    Instruction* ConvertIntoInstruction(std::vector<std::string> instruction);
};