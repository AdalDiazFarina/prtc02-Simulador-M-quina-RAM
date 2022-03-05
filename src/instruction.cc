/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2021-2022
 *
 * @author Adal Díaz Fariña
 * @since Mar 4 2022
 * @desc Instruction
 *			 This file contain the definitions of Instruction methods
 */

#include "../include/instruction.h"

// @brief Default constructor
Instruction::Instruction() {}

/*
* @brief Constructor
* @param label {String} label to jump into this instruction
* @param name {String} operator of the instruction
* @param operand {String} operand o tag follow the instruction
*/
Instruction::Instruction(std::string label, std::string name, std::string operand) {
  _label = label;
  _operator = name;
  _operand = operand;
}

// @brief Destructor
Instruction::~Instruction() {}

/*  
* @brief This method return the label
* @return _label {String}
*/
std::string Instruction::GetLabel() {
  return _label;
}

/*
* @brief This method return the operand
* @return _operand {String}
*/
std::string Instruction::GetOperand() {
  return _operand;
}

/*
* @brief This method return the instruction operator
* @return _operator {String} 
*/
std::string Instruction::GetOperator() {
  return _operator;
}

/*
* @brief << Overload operator. This methos show the isntruction
* @param os {ostream}
* @param instruction {Instruction} 
* @return {String} return the instruction in string format
*/
std::ostream& operator<<(std::ostream& os, Instruction& instruction) {
  if (instruction.GetLabel() == "") {
    os << instruction.GetOperator() << " " << instruction.GetOperand() << "\n";
  } else {
    os << instruction.GetLabel() << " " << instruction.GetOperator() << " " << instruction.GetOperand() << "\n";
  }
  return os;
}

// This methos is in charge of the instruction's function
void Instruction::Run() {}

// Load
Load::Load(std::string label, std::string name, std::string operand): Instruction(label, name, operand) {}
Load::~Load() {}

void Load::Run() {}

// Store
Store::Store(std::string label, std::string name, std::string operand): Instruction(label, name, operand) {}
Store::~Store() {}

void Store::Run() {}


// Add

Add::Add(std::string label, std::string name, std::string operand): Instruction(label, name, operand) {}
Add::~Add() {}

void Add::Run() {}

// Sub

Sub::Sub(std::string label, std::string name, std::string operand): Instruction(label, name, operand) {}
Sub::~Sub() {}

void Sub::Run() {}

// Mul

Mul::Mul(std::string label, std::string name, std::string operand): Instruction(label, name, operand) {}
Mul::~Mul() {}

void Mul::Run() {}

// Div

Div::Div(std::string label, std::string name, std::string operand): Instruction(label, name, operand) {}
Div::~Div() {}

void Div::Run() {}

// Read

Read::Read(std::string label, std::string name, std::string operand): Instruction(label, name, operand) {}
Read::~Read() {}

void Read::Run() {}

// Write

Write::Write(std::string label, std::string name, std::string operand): Instruction(label, name, operand) {}
Write::~Write() {}

void Write::Run() {}

// Jump

Jump::Jump(std::string label, std::string name, std::string operand): Instruction(label, name, operand) {}
Jump::~Jump() {}

void Jump::Run() {}

// Jzero

Jzero::Jzero(std::string label, std::string name, std::string operand): Instruction(label, name, operand) {}
Jzero::~Jzero() {}

void Jzero::Run() {}

// Jgtz

Jgtz::Jgtz(std::string label, std::string name, std::string operand): Instruction(label, name, operand) {}
Jgtz::~Jgtz() {}

void Jgtz::Run() {}

// Halt

Halt::Halt(std::string label, std::string name, std::string operand): Instruction(label, name, operand) {}
Halt::~Halt() {}

void Halt::Run() {}