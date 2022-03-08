/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2021-2022
 *
 * @author Adal Díaz Fariña
 * @since Mar 4 2022
 * @desc Read the input data
 *			 This file contain the definition of ReadData methods
 */

#include "../include/read_data.h"

// Default constructor
ReadData::ReadData() {}

/**
* @brief Constructor
* @param ram_program [std::string] name of the file with the ram program
*/
ReadData::ReadData(std::string ram_program) {
  std::ifstream program;
  std::string line;
  std::vector<std::string> data; 
  program.open(ram_program);
  if (program.is_open()) {
    while(!program.eof()) {
      getline(program, line);
      if (line.length() > 1 && line.find("#") == std::string::npos) {
        data.push_back(line);
      }
    }
    LinesToInstruction(data);
  } else {
    throw "Error. The file can`t be opened";
  }
}

// Destructor
ReadData::~ReadData() {}

/**
 * @brief This method transform the lines into instructions and save the in 
 * @param data [Array] with all the filtered line
 */
void ReadData::LinesToInstruction(std::vector<std::string> data) {
  std::vector<std::string> transform_data;
  std::vector<Instruction*> instructions;
  for (std::string line : data) {
    transform_data = Split(line, " ");
    instructions.push_back(ConvertIntoInstruction(transform_data));
  }
  _program_memory = new ProgramMemory(instructions);
}

/**
* @brief Get the Program Memory object
* @return [ProgramMemory] 
*/
ProgramMemory ReadData::GetProgramMemory() {
  return *(_program_memory);
}

/**
* @brief This method separate the string whit the delimiter
* @param str [std::string] string to separate
* @param delimiter [std::string] delimiter by which the string is separated
* @return [std::vector<std::string>] Vector of the separate elements
*/
std::vector<std::string> ReadData::Split(std::string str, std::string delimiter) {
  std::vector<std::string> array;
  std::string element;
  int pos;
  if (str.find("\t") != std::string::npos) str.replace(str.begin() + str.find("\t"), str.begin() + str.find("\t") + 1, " ");
  while((pos = str.find(delimiter)) != std::string::npos) {
    element = str.substr(0, pos);
    element = element.erase(0, element.find_first_not_of("\t\r\n"));
    array.push_back(element);
    str.erase(0, pos + delimiter.length());
  }
  str = str.erase(0, str.find_first_not_of(" \t\r\n"));
  array.push_back(str);
  return array;
}

/**
 * @brief This method transform the split line into a instruction
 * @param instruction [String] split line
 * @return [Instruction] 
 */
Instruction* ReadData::ConvertIntoInstruction(std::vector<std::string> instruction) {
  std::string label, name, operand;
  if (instruction.size() == 2) {
    if (instruction[1] == "HALT" || instruction[1] == "halt") {
      label = instruction[0];
      name = instruction[1];
      operand = "";
    } else {
      label = "";
      name = instruction[0];
      operand = instruction[1];
    }
  } else if (instruction.size() == 3) {
    label = instruction[0];
    name = instruction[1];
    operand = instruction[2];
  }
  if (name == "LOAD" || name == "load")return new Load(label, name, operand);
  if (name == "STORE" || name == "store")return new Store(label, name, operand);
  if (name == "ADD" || name == "add")return new Add(label, name, operand);
  if (name == "SUB" || name == "sub")return new Sub(label, name, operand);
  if (name == "MUL" || name == "mul")return new Mul(label, name, operand);
  if (name == "DIV" || name == "div")return new Div(label, name, operand);
  if (name == "READ" || name == "read")return new Read(label, name, operand);
  if (name == "WRITE" || name == "write")return new Write(label, name, operand);
  if (name == "JUMP" || name == "jump")return new Jump(label, name, operand);
  if (name == "JZERO" || name == "jzero")return new Jzero(label, name, operand);
  if (name == "JGTZ" || name == "jgtz")return new Jgtz(label, name, operand);
  if (name == "HALT" || name == "halt")return new Halt(label, name, operand);
}