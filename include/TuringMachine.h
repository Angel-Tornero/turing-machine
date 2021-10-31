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
    Alphabet* input_alphabet_;
    Alphabet* tape_alphabet_;
    char blank_symbol_;
    std::set<State*> Q_;
    std::set<State*> F_;
    std::set<Transition*> delta_;
    State* initial_state_;
    Tape tape_;
    int head_;

    /**
     * @brief Parse the alphabet in the input file
     * @param file
     * @return set with the symbols of the alphabet
     */
    std::set<char> parseAlphabet(std::ifstream& file);
    /**
     * @brief Parse the transition function in the input file
     * @param file
     * @param state_map
     */
    void parseTransitionFunction(std::ifstream& file, std::map<std::string, State*>& state_map);
    /**
     * @brief Recursive function to recognize strings
     * @param string
     * @param current
     * @param pushing_array
     * @param trace
     * @param output_file
     * 
     * @return bool
     */

  public:
    TuringMachine(std::string& file_name);
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