/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2021-2022
 *
 * @author Adal Díaz Fariña
 * @since Mar 4 2022
 * @desc Input unit
 *			 This file contain the definition of InputUnit class methods
 */

#include "../include/input_unit.h"

// Default constructor
InputUnit::InputUnit(): Tape();
/**
* @brief Construct a new Input Unit object
* @param tape [Tape]
*/
InputUnit::InputUnit(std::vector<int> tape): Tape(tape);
// Destructor
InputUnit::~InputUnit() {}

/**
* @brief This method read one value of the input tape
* @param pos [int] position of the value
* @return [int] 
*/
int InputUnit::Read(int pos) {
  return _tape;
}
