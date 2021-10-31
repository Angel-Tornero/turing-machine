/**
 * @file Transition.cc
 * @author Ángel Tornero Hernández
 * @brief Universidad de La Laguna
 * @brief Escuela Superior de Ingeniería y Tecnología
 * @brief Grado en Ingeniería Informática
 * @brief Complejidad Computacional
 * @version 1.0
 * @date 2021-10-31
 * 
 */

#include "State.h"

#ifndef _TRANSITION_
#define _TRANSITION_

const int RIGHT = 1;
const int LEFT = -1;
/**
 * @class Transition
 * 
 */
class Transition {
  private:
    friend class TuringMachine;
    State* start_state_;
    char tape_symbol_;
    State* next_state_;
    char input_symbol_;
    int move_;
  public:
    Transition(State*, char, State*, char, int);
};

#endif