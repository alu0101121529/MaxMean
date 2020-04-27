/**
 * @file grasp.hpp
 * @author Guillermo Hernández González
 * @brief Fichero que contiene la clase Grasp que tiene los métodos necesarios para resolver
 *        el algoritmo Max Mean usando GRASP
 * @version 1.0
 * @date 2020-04-27
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#pragma once
#include "algorithm.hpp"

/**
 * @class Grasp
 * 
 * @brief Grasp implementation to solve Max Mean
 * 
 */
class Grasp : public Algorithm
{
private:
  int Iterations;
  int NoImprov;
  bool anxious;
public:
/**
 * @brief Construct a new Grasp object
 * 
 * @param filename 
 * @param iter 
 * @param noimprov 
 * @param anx 
 */
  Grasp(std::string filename, int iter, int noimprov, bool anx) : Algorithm(filename), Iterations(iter), NoImprov(noimprov), anxious(anx) {}
  /**
   * @brief Function to create a initial solution for the problem
   * 
   * @param firstCandidates 
   * @return std::vector<int> 
   */
  std::vector<int> constructionPhase(std::vector<int> firstCandidates);
  /**
   * @brief Function to create a RCL array based on an initial solution
   * 
   * @return std::vector<int> 
   */
  std::vector<int> RCL(std::vector<int>, std::vector<int>);
  /**
   * @brief Function that uses a greedy algorithm to improve the solution
   * 
   * @return std::vector<int> 
   */
  std::vector<int> localSearch(std::vector<int>, std::vector<int>);
  /**
   * @brief Return the worst node (worst afinity) in the actual solution
   * 
   * @return std::pair<int,bool> 
   */
  std::pair<int,bool> getWorstMd(std::vector<int>);
  /**
   * @brief Method that executes the algorithm
   * 
   * @return std::vector<int> 
   */
  std::vector<int> execute();
};