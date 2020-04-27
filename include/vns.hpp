/**
 * @file vns.hpp
 * @author Guillermo Hernández González
 * @brief Fichero que contiene la clase Vns que tiene los métodos necesarios para resolver
 *        el algoritmo Max Mean usando VNS
 * @version 1.0
 * @date 2020-04-27
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#pragma once
#include "algorithm.hpp"

/**
 * @class Vns
 * 
 * @brief Vns implementation to solve Max Mean
 * 
 */

class Vns : public Algorithm
{
private:
  int Iterations;
  int NoImprov;
  bool anxious;
  int szTotal;
public:
  /**
   * @brief Construct a new Vns object
   * 
   * @param filename 
   * @param iter 
   * @param noimprov 
   * @param anx 
   * @param sz 
   */
  Vns(std::string filename, int iter, int noimprov, bool anx, int sz) : Algorithm(filename), Iterations(iter), NoImprov(noimprov), anxious(anx), szTotal(sz) {}
  /**
   * @brief Function to create a initial solution for the problem
   * 
   * @param firstCandidates 
   * @param solutionSize 
   * @return std::vector<int> 
   */
  std::vector<int> constructionPhase(std::vector<int> firstCandidates, int solutionSize);
  /**
   * @brief Creates a solutión with a specific neighborhood size
   * 
   * @param solSize 
   * @param firstCandidates 
   * @param addSize 
   * @return std::vector<int> 
   */
  std::vector<int> constructNeighborhood(int solSize, std::vector<int> firstCandidates, int addSize);
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