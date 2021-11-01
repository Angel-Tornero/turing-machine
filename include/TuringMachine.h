/**
 * @file TuringMachine.h
 * @author Ángel Tornero Hernández
 * @brief Universidad de La Laguna
 * @brief Escuela Superior de Ingeniería y Tecnología
 * @brief Grado en Ingeniería Informática
 * @brief Complejidad Computacional
 * @version 1.0
 * @date 2021-10-31
 * 
 */

#include "Alphabet.h"
#include "State.h"
#include "Tape.h"
#include "Transition.h"
#include <set>
#include <map>
#include <fstream>

/**
 * @class TuringMachine
 * 
 */
class TuringMachine {
  private:
    friend class TuringMachineReader;
    Alphabet* input_alphabet_;
    Alphabet* tape_alphabet_;
    char blank_symbol_;
    std::set<State*> Q_;
    std::set<State*> F_;
    std::set<Transition*> delta_;
    State* initial_state_;
    Tape tape_;
    int head_;

  public:
    TuringMachine()=default;
    ~TuringMachine();
    /**
     * @brief Parse the automaton given an input file
     * @param file_name
     */
    void parse(std::string& file_name);
    /**
     * @brief Checks if the automaton recognizes the given string
     * @param string
     * @param trace
     * @param output_file
     */
    bool exec(std::string string);
};