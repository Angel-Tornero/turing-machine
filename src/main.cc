#include "../include/TuringMachineReader.h"
#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {
  std::string file_name = argv[1];
  TuringMachineReader reader(file_name);
  TuringMachine automaton = reader.generateTM();
  std::string input_file_name;
  if (argc > 2) input_file_name = argv[2];
  std::ifstream input_file(input_file_name);
  std::string input;
  std::cout << '\n';
  if (!input_file.fail()) {
    while (!input_file.eof()) {
      std::getline(input_file, input);
      std::cout << '-' << input << ": ";
      std::cout << (automaton.exec(input)? "Si pertenece al lenguaje" : "No pertenece al lenguaje") << '\n';
    }
    std::cout << '\n';
    return 1;
  }
  std::cout << "A continuación, puede introducir cadenas por teclado para que la máquina de Turing las evalúe:\n\n";
  while (true) {
    std::string string;
    std::cout << "> ";
    std::cin >> string;
    input = string;
    std::cout << (automaton.exec(input)? "Si pertenece al lenguaje" : "No pertenece al lenguaje") << "\n\n";
  }
  return 0;
}