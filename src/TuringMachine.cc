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

TuringMachine::TuringMachine(std::string& file_name) {
  parse(file_name);
}

TuringMachine::~TuringMachine() {
  delete tape_alphabet_;
  delete input_alphabet_;
  for (auto element: Q_) delete element;
  for (auto element: delta_) delete element;
}

std::set<std::string> tokenizerToString(std::string& s) {
    std::stringstream ss(s);
    std::string word;
    std::set<std::string> set;
    while (ss >> word) {
        set.insert(word);
    }
    return set;
}

std::set<char> tokenizerToChar(std::string& s) {
    std::stringstream ss(s);
    char word;
    std::set<char> set;
    while (ss >> word) {
        set.insert(word);
    }
    return set;
}


std::ifstream openInputFile(std::string& file_name) {
  std::ifstream in_file(file_name);
  if (in_file.fail()) {
    std::cout << "No existe el archivo.\n";
    throw -1;
  }
  return in_file;
}

void TuringMachine::parse(std::string& file_name) {
  std::ifstream in_file = openInputFile(file_name);
  std::string temp_string;
  do {
    std::getline(in_file, temp_string);
    if (temp_string[0] == '#') std::cout << temp_string << '\n';
  } while (temp_string[0] == '#');
  
  //Conjunto Q
  std::set<std::string> states = tokenizerToString(temp_string);
  std::map<std::string, State*> state_map;
  for (auto element: states) {
    State* new_state = new State(element);
    state_map[element] = new_state;
    Q_.insert(new_state);
  }

  //Alfabeto de entrada
  input_alphabet_ = new Alphabet(parseAlphabet(in_file));

  //Alfabeto de cinta
  tape_alphabet_ = new Alphabet(parseAlphabet(in_file));

  //Estado inicial
  std::getline(in_file, temp_string);
  initial_state_ = state_map[temp_string];

  //Símbolo blanco
  std::getline(in_file, temp_string);
  blank_symbol_ = temp_string[0];
  input_alphabet_->symbols_.insert(blank_symbol_);

  //Conjunto F
  std::getline(in_file, temp_string);
  std::set<std::string> final_states = tokenizerToString(temp_string);
  for (auto element: final_states) {
    state_map[element]->final_state_ = true;
    F_.insert(state_map[element]);
  }

  //Funcion de transición
  parseTransitionFunction(in_file, state_map);
}

std::set<char> TuringMachine::parseAlphabet(std::ifstream& file) {
  std::string temp;
  std::getline(file, temp);
  std::set<char> alphabet = tokenizerToChar(temp);
  return alphabet;
}

void TuringMachine::parseTransitionFunction(std::ifstream& file, std::map<std::string, State*>& state_map) {
  std::string temp, start_state, finish_state;
  char input_symbol, tape_symbol, movement;
  while (std::getline(file, temp)) {
    std::istringstream iss(temp);
    iss >> start_state;
    iss >> tape_symbol;
    if (!tape_alphabet_->contain(tape_symbol)) throw "Caracter erróneo.";
    iss >> finish_state;
    iss >> input_symbol;
    if (!input_alphabet_->contain(input_symbol)) throw "Caracter erróneo.";
    iss >> movement;
    int move = ((movement == 'R')? RIGHT : LEFT);
    Transition* new_transition = new Transition(state_map[start_state], tape_symbol, state_map[finish_state], input_symbol, move);
    state_map[start_state]->addTransition(tape_symbol, new_transition);
  }
}

bool TuringMachine::exec(std::string string) {
  tape_ = Tape(string, blank_symbol_);
  head_ = 10;
  State* current_state = initial_state_;
  while (!current_state->final_state_) {
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