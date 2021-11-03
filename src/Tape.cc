#include "../include/Tape.h"
#include <iostream>

Tape::Tape(std::string string, char blank_symbol) {
  for (int i = 0; i < 3; i++) tape_.push_back(blank_symbol);
  for (auto symbol: string) tape_.push_back(symbol);
  tape_.push_back(blank_symbol);
}

char& Tape::operator[](int pos) {
  if (pos == (int)tape_.size() - 1) tape_.push_back(tape_[0]);
  return tape_[pos];
}

std::ostream& Tape::operator<<(std::ostream& os) {
  os << "╦";
  for (unsigned i = 0; i < tape_.size(); i++) {
    os << "═╦";
  }
  os << "\n║";
  for (auto character: tape_) {
    os << character << "║";
  }
  os << "\n╩";
  for (unsigned i = 0; i < tape_.size(); i++) {
    os << "═╩";
  }
  os << "\n";
  return os;
}