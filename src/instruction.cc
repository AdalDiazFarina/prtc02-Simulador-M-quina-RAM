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
void Instruction::Run(DataMemory& data_memory, InputUnit& input_unit, OutputUnit& output_unit, ProgramMemory& program_memory) {}

// Load
Load::Load(std::string label, std::string name, std::string operand): Instruction(label, name, operand) {}
Load::~Load() {}

void Load::Run(DataMemory& data_memory, InputUnit& input_unit, OutputUnit& output_unit, ProgramMemory& program_memory) {
  std::cout << "LOAD \n";
  std::string::size_type sz;
  if (_operand.find("=") != std::string::npos) {
    data_memory.SetAcc(stoi(_operand.substr(1, 2),  &sz));
  } else if (_operand.find("*") != std::string::npos) {
    data_memory.SetAcc(data_memory.GetRegister(data_memory.GetRegister(stoi(_operand.substr(1, 2), &sz))));
  } else {
    data_memory.SetAcc(data_memory.GetRegister(stoi(_operand, &sz)));
  }
}

// Store
Store::Store(std::string label, std::string name, std::string operand): Instruction(label, name, operand) {}
Store::~Store() {}

void Store::Run(DataMemory& data_memory, InputUnit& input_unit, OutputUnit& output_unit, ProgramMemory& program_memory) {
  std::cout << "STORE \n";
  std::string::size_type sz;
  if (_operand.find("*") != std::string::npos) {
    data_memory.SetRegister(data_memory.GetRegister(stoi(_operand.substr(1, 2), &sz)), data_memory.GetAcc());
  } else if (_operand.find("=") != std::string::npos) {
    std::cout << "Error. The " << _operator << " instruction not working properly \n";
    program_memory.HaltPosition();
  } else {
    data_memory.SetRegister((stoi(_operand, &sz)), data_memory.GetAcc());
  }
}

// Add
Add::Add(std::string label, std::string name, std::string operand): Instruction(label, name, operand) {}
Add::~Add() {}

void Add::Run(DataMemory& data_memory, InputUnit& input_unit, OutputUnit& output_unit, ProgramMemory& program_memory) {
  std::cout << "ADD \n";
  std::string::size_type sz;
  if (_operand.find("=") != std::string::npos) {
    data_memory.SetAcc(data_memory.GetAcc() + stoi(_operand.substr(1, 2), &sz));
  } else if (_operand.find("*") != std::string::npos) {
    data_memory.SetAcc(data_memory.GetAcc() + data_memory.GetRegister((data_memory.GetRegister(stoi(_operand.substr(1, 2), &sz)))));
  } else {
    data_memory.SetAcc(data_memory.GetAcc() + data_memory.GetRegister(stoi(_operand, &sz)));
  }
}

// Sub
Sub::Sub(std::string label, std::string name, std::string operand): Instruction(label, name, operand) {}
Sub::~Sub() {}

void Sub::Run(DataMemory& data_memory, InputUnit& input_unit, OutputUnit& output_unit, ProgramMemory& program_memory) {
  std::cout << "SUB \n";
  std::string::size_type sz;
  if (_operand.find("=") != std::string::npos) {
    data_memory.SetAcc(data_memory.GetAcc() - stoi(_operand.substr(1, 2), &sz));
  } else if (_operand.find("*") != std::string::npos) {
    data_memory.SetAcc(data_memory.GetAcc() - data_memory.GetRegister((data_memory.GetRegister(stoi(_operand.substr(1, 2), &sz)))));
  } else {
    data_memory.SetAcc(data_memory.GetAcc() - data_memory.GetRegister(stoi(_operand, &sz)));
  }
}

// Mul
Mul::Mul(std::string label, std::string name, std::string operand): Instruction(label, name, operand) {}
Mul::~Mul() {}

void Mul::Run(DataMemory& data_memory, InputUnit& input_unit, OutputUnit& output_unit, ProgramMemory& program_memory) {
  std::cout << "MUL \n";
  std::string::size_type sz;
  if (_operand.find("=") != std::string::npos) {
    data_memory.SetAcc(data_memory.GetAcc() * stoi(_operand.substr(1, 2), &sz));
  } else if (_operand.find("*") != std::string::npos) {
    data_memory.SetAcc(data_memory.GetAcc() * data_memory.GetRegister((data_memory.GetRegister(stoi(_operand.substr(1, 2), &sz)))));
  } else {
    data_memory.SetAcc(data_memory.GetAcc() * data_memory.GetRegister(stoi(_operand, &sz)));
  }
}

// Div
Div::Div(std::string label, std::string name, std::string operand): Instruction(label, name, operand) {}
Div::~Div() {}

void Div::Run(DataMemory& data_memory, InputUnit& input_unit, OutputUnit& output_unit, ProgramMemory& program_memory) {
  std::cout << "DIV \n";
  std::string::size_type sz;
  if (_operand.find("=") != std::string::npos) {
    data_memory.SetAcc(data_memory.GetAcc() / stoi(_operand.substr(1, 2), &sz));
  } else if (_operand.find("*") != std::string::npos) {
    data_memory.SetAcc(data_memory.GetAcc() / data_memory.GetRegister((data_memory.GetRegister(stoi(_operand.substr(1, 2), &sz)))));
  } else {
    data_memory.SetAcc(data_memory.GetAcc() / data_memory.GetRegister(stoi(_operand, &sz)));
  }
}

// Read
Read::Read(std::string label, std::string name, std::string operand): Instruction(label, name, operand) {}
Read::~Read() {}

void Read::Run(DataMemory& data_memory, InputUnit& input_unit, OutputUnit& output_unit, ProgramMemory& program_memory) {
  std::cout << "READ \n";
  std::string::size_type sz;
  if (input_unit.GetTape().size() > 0) {
    if (_operand.find("*") != std::string::npos || _operand.find("=") != std::string::npos) {
      std::cout << "Error. The " << _operator << " instruction not working properly \n";
      program_memory.HaltPosition();
    } 
    else {
      data_memory.SetRegister(stoi(_operand, &sz), input_unit.Read());
    }
  }
}

// Write
Write::Write(std::string label, std::string name, std::string operand): Instruction(label, name, operand) {}
Write::~Write() {}

void Write::Run(DataMemory& data_memory, InputUnit& input_unit, OutputUnit& output_unit, ProgramMemory& program_memory) {
  std::cout << "WRITE \n";
  std::string::size_type sz;
  if (_operand.find("=") != std::string::npos) {
    if (stoi(_operand.substr(1, 2), &sz) > 0) {
      output_unit.Write(stoi(_operand.substr(1, 2), &sz));
    } else {
      std::cout << "Error. The " << _operator << " instruction not working properly \n";
      program_memory.HaltPosition();
    }
  } else if (_operand.find("*") != std::string::npos) {
    if (stoi(_operand.substr(1, 2), &sz) > 0) {
      output_unit.Write(data_memory.GetRegister(data_memory.GetRegister(stoi(_operand.substr(1, 2), &sz))));
    } else {
      std::cout << "Error. The " << _operator << " instruction not working properly \n";
      program_memory.HaltPosition();
    }
  } else {
    if (stoi(_operand ,&sz) > 0) {
      output_unit.Write(data_memory.GetRegister(stoi(_operand, &sz)));
    } else {
      std::cout << "Error. The " << _operator << " instruction not working properly \n";
      program_memory.HaltPosition();
    }
  }
}

// Jump
Jump::Jump(std::string label, std::string name, std::string operand): Instruction(label, name, operand) {}
Jump::~Jump() {}

void Jump::Run(DataMemory& data_memory, InputUnit& input_unit, OutputUnit& output_unit, ProgramMemory& program_memory) {
  std::cout << "JUMP \n";
  if (_operand.find("=") != std::string::npos || _operand.find("*") != std::string::npos) {
    std::cout << "Error. The " << _operator << " instruction not working properly \n";
    program_memory.HaltPosition();
  } else {
    program_memory.FindLabel(_operand);
  }
}

// Jzero
Jzero::Jzero(std::string label, std::string name, std::string operand): Instruction(label, name, operand) {}
Jzero::~Jzero() {}

void Jzero::Run(DataMemory& data_memory, InputUnit& input_unit, OutputUnit& output_unit, ProgramMemory& program_memory) {
  std::cout << "JZERO \n";
  if (_operand.find("=") != std::string::npos || _operand.find("*") != std::string::npos) {
    std::cout << "Error. The " << _operator << " instruction not working properly \n";
    program_memory.HaltPosition();
  } else {
    if (data_memory.GetAcc() == 0) {
      program_memory.FindLabel(_operand);
    }
  } 
}

// Jgtz
Jgtz::Jgtz(std::string label, std::string name, std::string operand): Instruction(label, name, operand) {}
Jgtz::~Jgtz() {}

void Jgtz::Run(DataMemory& data_memory, InputUnit& input_unit, OutputUnit& output_unit, ProgramMemory& program_memory) {
  std::cout << "JGTZ \n";
  if (_operand.find("=") != std::string::npos || _operand.find("*") != std::string::npos) {
    std::cout << "Error. The " << _operator << " instruction not working properly \n";
    program_memory.HaltPosition();
  } else {
    if (data_memory.GetAcc() > 0) program_memory.FindLabel(_operand);
  }
}

// Halt
Halt::Halt(std::string label, std::string name, std::string operand): Instruction(label, name, operand) {}
Halt::~Halt() {}

void Halt::Run(DataMemory& data_memory, InputUnit& input_unit, OutputUnit& output_unit, ProgramMemory& program_memory) {
  std::cout << "HALT \n";
  std::cout << "End of the program \n"; 
}