/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2021-2022
 *
 * @author Adal Díaz Fariña
 * @since Mar 4 2022
 * @desc Tape
 *			 This file contain the declaration of tape class methods
 */

#pragma once
#include <iostream>
#include <vector>
#include <fstream>

/**
 * @brief This class represent a tape
 * @param _tape [std::vector<int>] This vector contain the values of the tape
 * @param _pos [int] Contain the position of head tape 
 */
class Tape {
  protected:
    std::vector<int> _tape;
    int _pos;
  public:
    // Default constructor
    Tape();
    Tape(std::vector<int> tape);
    // Destructor
    ~Tape();
    /**
     * @brief Get the Tape object
     * @return std::vector<int> 
     */
    std::vector<int> GetTape();
    /**
     * @brief Overload operator <<
     * @param os [std::ostream&]
     * @param tape [Tape&]
     * @return std::ostream& 
     */
    friend std::ostream& operator<<(std::ostream& os, Tape& tape);
};