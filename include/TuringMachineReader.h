/**
 * @file TuringMachineReader.h
 * @author Ángel Tornero Hernández
 * @brief Universidad de La Laguna
 * @brief Escuela Superior de Ingeniería y Tecnología
 * @brief Grado en Ingeniería Informática
 * @brief Complejidad Computacional
 * @version 1.0
 * @date 2021-10-31
 * 
 */

#include "TuringMachine.h"

/**
 * @class TuringMachineReader
 * 
 */
class TuringMachineReader {
  private:
    std::ifstream input_file_;
    std::map<std::string, State*> state_map_;
    /**
     * @brief Parse the alphabet in the input file
     * @param file
     * @return set with the symbols of the alphabet
     */
    std::set<char> readAlphabet();
    /**
     * @brief Parse the transition function in the input file
     * @param file
     * @param state_map
     */
    void readTransitionFunction(TuringMachine&);
  public:
    TuringMachineReader(std::string& file_name);
    ~TuringMachineReader()=default;
    void generateTM(TuringMachine&);
};