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

#include <vector>
#include <string>

/**
 * @class Tape
 * 
 */
class Tape {
  private:
    std::vector<char> tape_;
  public:
    Tape()=default;
    Tape(std::string string, char blank_symbol);
    char& operator[](int);
    std::ostream& operator<<(std::ostream&);
};