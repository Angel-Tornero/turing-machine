#include "../include/TuringMachineReader.h"
#include <sstream>
#include <fstream>
#include <iostream>

std::ifstream openInputFile(std::string& file_name) {
  std::ifstream input_file(file_name);
  if (input_file.fail()) {
    throw "No existe el archivo";
  }
  return input_file;
}

TuringMachineReader::TuringMachineReader(std::string& file_name) {
  input_file_ = openInputFile(file_name);
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

TuringMachine TuringMachineReader::generateTM() {
  std::string temp_string;
  do {
    std::getline(input_file_, temp_string);
    if (temp_string[0] == '#') std::cout << temp_string << '\n';
  } while (temp_string[0] == '#');
  
  //Conjunto Q
  std::set<std::string> states = tokenizerToString(temp_string);
  for (auto element: states) {
    State* new_state = new State(element);
    state_map_[element] = new_state;
    turing_machine_.Q_.insert(new_state);
  }

  //Alfabeto de entrada
  turing_machine_.input_alphabet_ = new Alphabet(readAlphabet());

  //Alfabeto de cinta
  turing_machine_.tape_alphabet_ = new Alphabet(readAlphabet());

  //Estado inicial
  std::getline(input_file_, temp_string);
  turing_machine_.initial_state_ = state_map_[temp_string];

  //Símbolo blanco
  std::getline(input_file_, temp_string);
  turing_machine_.blank_symbol_ = temp_string[0];
  turing_machine_.input_alphabet_->symbols_.insert(turing_machine_.blank_symbol_);

  //Conjunto F
  std::getline(input_file_, temp_string);
  std::set<std::string> final_states = tokenizerToString(temp_string);
  for (auto element: final_states) {
    state_map_[element]->final_state_ = true;
    turing_machine_.F_.insert(state_map_[element]);
  }

  //Funcion de transición
  readTransitionFunction();
  return turing_machine_;
}

std::set<char> TuringMachineReader::readAlphabet() {
  std::string temp;
  std::getline(input_file_, temp);
  std::set<char> alphabet = tokenizerToChar(temp);
  return alphabet;
}

void TuringMachineReader::readTransitionFunction() {
  std::string temp, start_state, finish_state;
  char input_symbol, tape_symbol, movement;
  while (std::getline(input_file_, temp)) {
    std::istringstream iss(temp);
    iss >> start_state;
    iss >> tape_symbol;
    if (!turing_machine_.tape_alphabet_->contain(tape_symbol)) throw "Caracter erróneo.";
    iss >> finish_state;
    iss >> input_symbol;
    if (!turing_machine_.input_alphabet_->contain(input_symbol)) throw "Caracter erróneo.";
    iss >> movement;
    int move = ((movement == 'R')? RIGHT : LEFT);
    Transition* new_transition = new Transition(state_map_[start_state], tape_symbol, state_map_[finish_state], input_symbol, move);
    state_map_[start_state]->addTransition(tape_symbol, new_transition);
  }
}