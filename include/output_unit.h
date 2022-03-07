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

#pragma once
#include "tape.h"

/**
 * @brief This class represent the output unit. Output unit is in charge of manage the output data 
 * 
 */
class OutputUnit : public Tape {
  private:
    std::ofstream _output_file;
  public: 
    // Constructor
    OutputUnit(std::string output_file);
    // Destructor
    ~OutputUnit();
    /**
     * @brief This method insert one value in the output tape
     * @param value 
     */
    void Write(int value);
    /**
     * @brief This method write the output tape in a file
     */
    void WriteInFile();
};