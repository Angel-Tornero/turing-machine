#include "../include/Transition.h"

Transition::Transition(State* start_state, char tape_symbol, State* next_state, char input_symbol, int move) {
  start_state_ = start_state;
  tape_symbol_ = tape_symbol;
  next_state_ = next_state;
  input_symbol_ = input_symbol;
  move_ = move;
}