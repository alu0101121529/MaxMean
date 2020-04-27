/**
 * @file greedyAlgorithm.hpp
 * @author Guillermo Hernández González
 * @brief Fichero que contiene la implementación del algoritmo greedy
 *        de forma constructiva.
 * @version 1.0
 * @date 2020-04-27
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#pragma once
#include "matrix.hpp"
#include "algorithm.hpp"
/**
 * @brief Implementation of the greedy algorithm to solve
 *        Max Mean problem
 * 
 */
class greedyAlgorithm : public Algorithm
{
private:
public:
  /**
   * @brief Construct a new greedy Algorithm object
   * 
   * @param filename 
   */
  greedyAlgorithm(std::string filename) : Algorithm(filename) {}
  /**
   * @brief Method that executes the algorithm
   * 
   * @return std::vector<int> 
   */
  std::vector<int> execute();
  /**
   * @brief Returns the node with the max mean dispersion
   * 
   * @param solution 
   * @return std::pair<int, bool> 
   */
  std::pair<int, bool> maximizeMd(std::vector<int> solution);
};