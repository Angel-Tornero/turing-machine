#include "../include/Tape.h"
#include <iostream>

Tape::Tape(std::string string, char blank_symbol) {
  for (int i = 0; i < 10; i++) tape_.push_back(blank_symbol);
  for (auto symbol: string) tape_.push_back(symbol);
  for (int i = 0; i < 10; i++) tape_.push_back(blank_symbol);
}

char& Tape::operator[](int pos) {
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