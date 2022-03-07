/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2021-2022
 *
 * @author Adal Díaz Fariña
 * @since Mar 4 2022
 * @desc Data memory
 *			 This file contain the definition of DataMemory methods
 */

#include "../include/data_memory.h"

// Default contructor
DataMemory::DataMemory() {
  _acc = 0;
  _registers = {};
}

// Destructor 
DataMemory::~DataMemory() {
  _registers.clear();
}


/**
* @brief This method get the register in the specified position
* @param pos [int]
* @return [int]
*/
int DataMemory::GetRegister(int pos) {
  return _registers[pos];
}

/**
* @brief This method get the special accumulator register
* @return [int] 
*/
int DataMemory::GetAcc() {
  return _acc;
}

/**
* @brief This method change the value of the accumulator register
* @param operand [int]
*/
void DataMemory::SetAcc(int acc) {
  _acc = acc;
}

/**
* @brief This method add a new register in the specified position
* @param pos [int]
* @param value [int]
*/
void DataMemory::SetRegister(int pos, int value) {
  _registers[pos] = value;
}

/**
* @brief This method search one register in the list
* @param number [int] Number of the register
* @return [int] 
*/
int DataMemory::FindRegister(int number) {
  for (int i = 0; i < _registers.size(); i++) {
    if (_registers[i] == number) return i;
  }
  return -1;
}