/**
 * @file matrix.hpp
 * @author Guillermo Hernández González
 * @brief Fichero que contiene la implementación de una clase Matriz que servirá
 *        como base para guardar los datos dado por fichero
 * @version 1.0
 * @date 2020-04-27
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <string>
#include <utility>

/**
 * @class Matriz
 * @brief Matrix containing all the distances between nodes
 * 
 */
class Matriz
{
private:
  std::vector<std::vector<int>> matrix;

public:
  /**
   * @brief Construct a new Matriz object
   * 
   * @param {std::string} filename 
   */
  Matriz(std::string filename) : matrix(0, std::vector<int>(0))
  {
    std::ifstream myFile;
    myFile.open(filename);
    int numeroVertices = 0;
    int valores = 0;
    if (myFile.is_open())
    {
      myFile >> numeroVertices;
    }
    this->resizeMatrix(numeroVertices, numeroVertices);
    for (int i = 0; i < numeroVertices; i++)
    {
      for (int j = 0; j < numeroVertices; j++)
      {
        matrix[i][j] = 0;
      }
    }
    for (int i = 0; i < numeroVertices; i++)
    {
      for (int j = 0; j < numeroVertices; j++)
      {
        if (!myFile.eof() && matrix[i][j] == 0 && i != j)
        {
          myFile >> valores;
          matrix[i][j] = valores;
          matrix[j][i] = valores;
        }
      }
    }
    myFile.close();
  }
  /**
   * @brief Change the matrix's dimensions
   * 
   * @param rows 
   * @param cols 
   */
  void resizeMatrix(int rows, int cols);
  /**
   * @brief Get the rows object
   * 
   * @return int 
   */
  int get_rows();
  /**
   * @brief Get the cols object
   * 
   * @return int 
   */
  int get_cols();
  /**
   * @brief Set the position object
   * 
   * @param row 
   * @param col 
   * @param value 
   */
  void set_position(int row, int col, int value);
  /**
   * @brief Get the position object
   * 
   * @param row 
   * @param col 
   * @return int 
   */
  int get_position(int row, int col);
  /**
   * @brief Print the matrix
   * 
   */
  void write();
  /**
   * @brief Operator [] overload
   * 
   * @param index 
   * @return std::vector<int>& 
   */
  std::vector<int> &operator[](int index);
  /**
   * @brief returns a pair with the two nodes with the 
   *        highest afinity
   * 
   * @return std::pair<int,int> 
   */
  std::pair<int,int> biggestAfinityPair();
  /**
   * @brief returns a vector of pairs that contains
   *        the nodes that have highest afinity
   * 
   * @return std::vector<std::pair<int,int>> 
   */
  std::vector<std::pair<int,int>> biggestAfinity();
  /**
   * @brief Returns the mean dispersion
   * 
   * @param solution 
   * @return float 
   */
  float getMd(std::vector<int> solution);
  /**
   * @brief Returns the mean dispersion
   * 
   * @param solution 
   * @return float 
   */
  float getMdPair(std::vector<std::pair<int,int>> solution);
  /**
   * @brief Returns a vector with all the nodes
   * 
   * @return std::vector<int> 
   */
  std::vector<int> getNodes();
};