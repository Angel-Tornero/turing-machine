/**
 * @file State.h
 * @author Ángel Tornero Hernández
 * @brief Universidad de La Laguna
 * @brief Escuela Superior de Ingeniería y Tecnología
 * @brief Grado en Ingeniería Informática
 * @brief Complejidad Computacional
 * @version 1.0
 * @date 2021-10-21
 * 
 */


#include <string>
#include <utility>
#include <map>
#include <set>
#include <vector>

#ifndef _STATE_
#define _STATE_

/**
 * @class State
 * 
 */

class Transition;
class State {
  private:
    friend class TuringMachineReader;
    friend class TuringMachine;
    std::string id_;
    std::map<char, Transition*> transition_function_;
    bool final_state_;
    /**
     * @brief Add a transition to the transition function of the State
     * @param symbols
     * @param destiny
     */
    void addTransition(char symbol, Transition* transition);
    State(std::string id);
  public:
    /**
     * @brief Return the transitions given a tape symbol and a stack symbol
     * @param tape_symbol
     * @param stack_symbol
     * 
     * @return std::set<std::pair<State*, std::vector<char>>>
     */
    Transition* transitionFunction(char symbol);
    /**
     * @brief Check if the current object is a final state
     * 
     * @return true 
     * @return false 
     */
    bool isFinalState();
};


#endif