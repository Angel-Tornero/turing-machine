/**
 * @file TuringMachine.cc
 * @author Ángel Tornero Hernández
 * @brief Universidad de La Laguna
 * @brief Escuela Superior de Ingeniería y Tecnología
 * @brief Grado en Ingeniería Informática
 * @brief Complejidad Computacional
 * @version 1.0
 * @date 2021-10-31
 * 
 */

#include "../include/TuringMachine.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <utility>
#include <iterator>

TuringMachine::~TuringMachine() {
  delete tape_alphabet_;
  delete input_alphabet_;
  for (auto element: Q_) delete element;
  for (auto element: delta_) delete element;
}

bool TuringMachine::exec(std::string string) {
  tape_ = Tape(string, blank_symbol_);
  head_ = 3;  //primer caracter de la cadena, los 3 primeros son simbolo blanco
  State* current_state = initial_state_;
  while (!current_state->isFinalState()) {
    Transition* transition = current_state->transitionFunction(tape_[head_]);
    if (transition == NULL) {
      tape_.operator<<(std::cout);
      return false;
    }
    tape_[head_] = transition->input_symbol_;
    head_ += transition->move_;
    current_state = transition->next_state_;
  }
  tape_.operator<<(std::cout);
  return true;
}