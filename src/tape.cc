/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2021-2022
 *
 * @author Adal Díaz Fariña
 * @since Mar 4 2022
 * @desc Tape
 *			 This file contain the definition of tape class methods
 */

#include "../include/tape.h"

// Default constructor
Tape::Tape() {
  _pos = 0;
  _tape = {};
}

/**
 * @brief Construct a new Tape object
 * @param tape [std::vector<int>]
 */
Tape::Tape(std::vector<int> tape) {
  _pos = 0;
  _tape = tape;
}

// Destructor
Tape::~Tape() {}

/**
* @brief Overload operator <<
* @param os [std::ostream&]
* @param tape [Tape&]
* @return std::ostream& 
*/

/**
* @brief Get the Tape object
* @return std::vector<int> 
*/
std::vector<int> Tape::GetTape() {
  return _tape;
}

std::ostream& operator<<(std::ostream& os, Tape& tape) {
  os << "[";
  for (int value : tape.GetTape()) {
    os << value << ", ";
  }
  os << "]";
  return os;
}