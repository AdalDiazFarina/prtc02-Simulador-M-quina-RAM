/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2021-2022
 *
 * @author Adal Díaz Fariña
 * @since Mar 4 2022
 * @desc Data memory
 *			 This file contain the declaration of DataMemory methods
 */

#pragma once
#include <iostream>
#include <vector>

/**
 * @brief This class represent the data memory. Data memory contain the register of ram machine
 * @param _acc [int]
 * @param _registers [std::vector<int>] 
 */ 
class DataMemory {
  private:
    int _acc;
    std::vector<int> _registers;
  public:
    // Default contructor
    DataMemory();
    // Destructor 
    ~DataMemory();

    // Getters and setters
    /**
     * @brief This method get the register in the specified position
     * @param pos [int]
     * @return [int]
     */
    int GetRegister(int pos);
    /**
     * @brief This method get the special accumulator register
     * @return [int] 
     */
    int GetAcc();
    /**
     * @brief This method change the value of the accumulator register
     * @param acc [int]
     */
    void SetAcc(int acc);
    /**
     * @brief This method add a new register in the specified position
     * @param pos [int]
     * @param value [int]
     */
    void SetRegister(int pos, int value); 

    /**
     * @brief This method search one register in the list
     * @param number [int] Number of the register
     * @return [int] 
     */
    int FindRegister(int number);
};
