/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2021-2022
 *
 * @author Adal Díaz Fariña
 * @since Mar 4 2022
 * @desc Instruction
 *			 This file contain the declaration of Instruction methods
 */

#pragma once
#include <iostream>
#include <fstream>
#include "input_unit.h"
#include "output_unit.h"
#include "data_memory.h"
#include "program_memory.h"

/*
* This class represent an instruction. Is the base class
* @param label {String} label to jump into this instruction
* @param operator {String} name of the instruction
* @param operand {String} operand o tag follow the instruction
*/
class Instruction {
  protected:
    std::string _label;
    std::string _operator;
    std::string _operand;
  
  public:
    // @brief Default constructor
    Instruction();
    /*
    * @brief Constructor
    * @param label {String} label to jump into this instruction
    * @param name {String} operator of the instruction
    * @param operand {String} operand o tag follow the instruction
    */
    Instruction(std::string label, std::string name, std::string operand);
    // @brief Destructor
    virtual ~Instruction();

    /*
    * @brief This method return the label
    * @return _label {String}
    */
    std::string GetLabel();
    /*
    * @brief This method return the operand
    * @return _operand {String}
    */
    std::string GetOperand();
    /*
    * @brief This method return the instruction operator
    * @return _operator {String} 
    */
    std::string GetOperator();
    /*
    * @brief << Overload operator. This methos show the isntruction
    * @param os {ostream}
    * @param instruction {Instruction} 
    * @return {String} return the instruction in string format
    */
    friend std::ostream& operator<<(std::ostream& os, Instruction& instruction);
    // This methos is in charge of the instruction's function
    virtual void Run();
};

class Load : public Instruction {
  public:
    Load(std::string label, std::string name, std::string operand);
    ~Load();

    void Run(DataMemory& _data_memory);
};

class Store : public Instruction {
  public:
    Store(std::string label, std::string name, std::string operand);
    ~Store();

    void Run(DataMemory& data_memory);
};

class Add : public Instruction {
  public:
    Add(std::string label, std::string name, std::string operand);
    ~Add();

    void Run(DataMemory& data_memory);
};

class Sub : public Instruction {
  public:
    Sub(std::string label, std::string name, std::string operand);
    ~Sub();

    void Run(DataMemory& data_memory);
};

class Mul : public Instruction {
  public:
    Mul(std::string label, std::string name, std::string operand);
    ~Mul();

    void Run(DataMemory& data_memory);
};

class Div : public Instruction {
  public:
    Div(std::string label, std::string name, std::string operand);
    ~Div();

    void Run(DataMemory& data_memory);
};

class Read : public Instruction {
  public:
    Read(std::string label, std::string name, std::string operand);
    ~Read();

    void Run(DataMemory& data_memory, InputUnit& input_unit);
};

class Write : public Instruction {
  public:
    Write(std::string label, std::string name, std::string operand);
    ~Write();

    void Run(DataMemory& data_memory, OutputUnit& output_unit);
};

class Jump : public Instruction {
  public:
    Jump(std::string label, std::string name, std::string operand);
    ~Jump();

    void Run(ProgramMemory& program_memory);
};

class Jzero : public Instruction {
  public:  
    Jzero(std::string label, std::string name, std::string operand);
    ~Jzero();

    void Run(ProgramMemory& program_memory, DataMemory& data_memory);
};

class Jgtz : public Instruction {
  public:
    Jgtz(std::string label, std::string name, std::string operand);
    ~Jgtz();

    void Run(ProgramMemory& program_memory, DataMemory& data_memory);
};

class Halt : public Instruction {
  public:  
    Halt(std::string label, std::string name, std::string operand);
    ~Halt();

    void Run();
};
