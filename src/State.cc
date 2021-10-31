/**
 * @file State.cc
 * @author Ángel Tornero Hernández
 * @brief Universidad de La Laguna
 * @brief Escuela Superior de Ingeniería y Tecnología
 * @brief Grado en Ingeniería Informática
 * @brief Complejidad Computacional
 * @version 1.0
 * @date 2021-10-21
 * 
 */


#include "../include/State.h"
#include <iostream>

State::State(std::string id) {
  final_state_ = false;
  id_ = id;
}

void State::addTransition(char symbol, Transition* transition) {
  transition_function_[symbol] = transition;
}

Transition* State::transitionFunction(char symbol) {
  if (transition_function_.find(symbol) != transition_function_.end()) {
    return transition_function_[symbol];
  }
  return NULL;
}