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

void Load::Run(DataMemory* data_memory) {
  std::string::size_type sz;
  if (_operand.find("=") != std::string::npos) {
    data_memory -> SetAcc(stoi(_operand.substr(1, 2)), &sz);
  } else if (_operand.find("*") != std::string::npos) {
    data_memory -> SetAcc(data_memory -> GetRegister((data_memory -> GetRegister((stoi(_operand.substr(1, 2), &sz)))));
  } else {
    data_memory -> SetAcc(data_memory -> GetRegister(stoi(_operand, &sz)));
  }
}

// Store
Store::Store(std::string label, std::string name, std::string operand): Instruction(label, name, operand) {}
Store::~Store() {}

void Store::Run(DataMemory& data_memory) {
  std::string::size_type sz;
  if (_operand.find("*") != std::string::npos) {
    data_memory -> SetRegister(data_memory -> GetRegister((stoi(_operand.substr(1, 2), &sz)), data_memory -> GetAcc());
  } else {
    data_memory -> SetRegister((stoi(_operand, &sz)), data_memory -> GetAcc());
  }
}

// Add
Add::Add(std::string label, std::string name, std::string operand): Instruction(label, name, operand) {}
Add::~Add() {}

void Add::Run(DataMemory& data_memory) {
  std::string::size_type sz;
  if (_operand.find("=") != std::string::npos) {
    data_memory -> SetAcc(data_memory -> GetAcc() + stoi(_operand.substr(1, 2), &sz));
  } else if (_operand.find("*") != std::string::npos) {
    data_memory -> SetAcc(data_memory -> GetAcc() + data_memory -> GetRegister((data_memory -> GetRegister(stoi(_operand.substr(1, 2), &sz)))));
  } else {
    data_memory -> SetAcc(data_memory -> GetAcc() + data_memory -> GetRegister(stoi(_operand, &sz)));
  }
}

// Sub
Sub::Sub(std::string label, std::string name, std::string operand): Instruction(label, name, operand) {}
Sub::~Sub() {}

void Sub::Run(DataMemory& data_memory) {
  std::string::size_type sz;
  if (_operand.find("=") != std::string::npos) {
    data_memory -> SetAcc(data_memory -> GetAcc() - stoi(_operand.substr(1, 2), &sz));
  } else if (_operand.find("*") != std::string::npos) {
    data_memory -> SetAcc(data_memory -> GetAcc() - data_memory -> GetRegister((data_memory -> GetRegister(stoi(_operand.substr(1, 2), &sz)))));
  } else {
    data_memory -> SetAcc(data_memory -> GetAcc() - data_memory -> GetRegister(stoi(_operand, &sz)));
  }
}

// Mul
Mul::Mul(std::string label, std::string name, std::string operand): Instruction(label, name, operand) {}
Mul::~Mul() {}

void Mul::Run(DataMemory& data_memory) {
  std::string::size_type sz;
  if (_operand.find("=") != std::string::npos) {
    data_memory -> SetAcc(data_memory -> GetAcc() * stoi(_operand.substr(1, 2), &sz));
  } else if (_operand.find("*") != std::string::npos) {
    data_memory -> SetAcc(data_memory -> GetAcc() * data_memory -> GetRegister((data_memory -> GetRegister(stoi(_operand.substr(1, 2), &sz)))));
  } else {
    data_memory -> SetAcc(data_memory -> GetAcc() * data_memory -> GetRegister(stoi(_operand, &sz)));
  }
}

// Div
Div::Div(std::string label, std::string name, std::string operand): Instruction(label, name, operand) {}
Div::~Div() {}

void Div::Run(DataMemory& data_memory) {
  std::string::size_type sz;
  if (_operand.find("=") != std::string::npos) {
    data_memory -> SetAcc(data_memory -> GetAcc() / stoi(_operand.substr(1, 2), &sz));
  } else if (_operand.find("*") != std::string::npos) {
    data_memory -> SetAcc(data_memory -> GetAcc() / data_memory -> GetRegister((data_memory -> GetRegister(stoi(_operand.substr(1, 2), &sz)))));
  } else {
    data_memory -> SetAcc(data_memory -> GetAcc() / data_memory -> GetRegister(stoi(_operand, &sz)));
  }
}

// Read
Read::Read(std::string label, std::string name, std::string operand): Instruction(label, name, operand) {}
Read::~Read() {}

void Read::Run(DataMemory& data_memory, InputUnit& input_unit) {
  std::string::size_type sz;
  if (_operand.find("*") != std::string::npos) {
    data_memory -> SetRegister(data_memory -> GetRegister((stoi(_operand.substr(1, 2), &sz))), input_unit.Read());
  } else {
    data_memory -> SetRegister(stoi(_operand, &sz), input_unit.Read());
  }
}

// Write
Write::Write(std::string label, std::string name, std::string operand): Instruction(label, name, operand) {}
Write::~Write(DataMemory& data_memory, OutputUnit& output_unit) {}

void Write::Run() {
  std::string::size_type sz;
  if (_operand.find("=") != std::string::npos) {
    output_unit -> Write(stoi(_operand.substr(1, 2), &sz));
  } else if (_operand.find("*") != std::string::npos) {
    output_unit -> Write(data_memory -> GetRegister(data_memory -> GetRegister(stoi(_operand.substr(1, 2), &sz))));
  } else {
    output_unit -> Write(data_memory -> GetRegister(stoi(_operand.substr(1, 2), &sz)));
  }
}

// Jump
Jump::Jump(std::string label, std::string name, std::string operand): Instruction(label, name, operand) {}
Jump::~Jump() {}

void Jump::Run(ProgramMemory& program_memory) {
  std::string::size_type sz;
  program_memory -> FindLabel(stoi(_operand, &sz));
}

// Jzero
Jzero::Jzero(std::string label, std::string name, std::string operand): Instruction(label, name, operand) {}
Jzero::~Jzero() {}

void Jzero::Run(ProgramMemory& program_memory, DataMemory& data_memory) {
  if (data_memory -> GetAcc() == 0) program_memory -> FindLabel(stoi(_operand, &sz));
}

// Jgtz
Jgtz::Jgtz(std::string label, std::string name, std::string operand): Instruction(label, name, operand) {}
Jgtz::~Jgtz() {}

void Jgtz::Run(ProgramMemory& program_memory, DataMemory& data_memory) {
  if (data_memory -> GetAcc() > 0) program_memory -> FindLabel(stoi(_operand, &sz));
}

// Halt
Halt::Halt(std::string label, std::string name, std::string operand): Instruction(label, name, operand) {}
Halt::~Halt() {}

void Halt::Run() {
  std::cout << "End of the program \n"; 
}