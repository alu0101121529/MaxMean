#include "../include/matrix.hpp"

void Matriz::resizeMatrix(int rows, int cols)
{
  for (int i = 0; i < matrix.size(); i++)
  {
    matrix[i].resize(cols);
  }
  matrix.resize(rows, std::vector<int>(cols));
}

int Matriz::get_rows()
{
  return matrix.size();
}

int Matriz::get_cols()
{
  return matrix[0].size();
}

void Matriz::set_position(int row, int col, int value)
{
  matrix[row][col] = value;
}

int Matriz::get_position(int row, int col)
{
  return matrix[row][col];
}

void Matriz::write()
{
  for (int i = 0; i < matrix.size(); i++)
  {
    for (int j = 0; j < matrix[0].size(); j++)
    {
      std::cout << "[" << matrix[i][j] << "] ";
    }
    std::cout << std::endl;
  }
}

std::vector<int> &Matriz::operator[](int index)
{
  if (index >= matrix.size())
  {
    std::cerr << "Index fuera de rango" << std::endl;
    std::exit(0);
  }
  else
  {
    return matrix[index];
  }
}

std::pair<int, int> Matriz::biggestAfinityPair()
{
  float biggestValue = 0;
  std::vector<std::pair<int, int>> vectorAfinity;
  for (int i = 0; i < matrix.size(); i++)
  {
    for (int j = i + 1; j < matrix.size(); j++)
    {
      if (matrix[i][j] >= biggestValue)
      {
        biggestValue = matrix[i][j];
      }
    }
  }
  for (int i = 0; i < matrix.size(); i++)
  {
    for (int j = i + 1; j < matrix.size(); j++)
    {
      if (matrix[i][j] == biggestValue)
      {
        vectorAfinity.push_back(std::pair<int, int>(i, j));
      }
    }
  }
  return vectorAfinity[rand() % vectorAfinity.size()];
}

float Matriz::getMd(std::vector<int> solution)
{
  float sumOfAfinities = 0;
  for (int i = 0; i < solution.size(); i++)
  {
    for (int j = i + 1; j < solution.size(); j++)
    {
      sumOfAfinities += matrix[solution[i]][solution[j]];
    }
  }
  return sumOfAfinities / solution.size();
}

std::vector<std::pair<int,int>> Matriz::biggestAfinity()
{
  float biggestValue = 0;
  std::vector<std::pair<int, int>> vectorAfinity;
  for (int i = 0; i < matrix.size(); i++)
  {
    for (int j = i + 1; j < matrix.size(); j++)
    {
      if (matrix[i][j] >= biggestValue)
      {
        biggestValue = matrix[i][j];
      }
    }
  }
  for (int i = 0; i < matrix.size(); i++)
  {
    for (int j = i + 1; j < matrix.size(); j++)
    {
      if (matrix[i][j] == biggestValue)
      {
        vectorAfinity.push_back(std::pair<int, int>(i, j));
      }
    }
  }
  return vectorAfinity;
}


float Matriz::getMdPair(std::vector<std::pair<int,int>> solution)
{
  float sumOfAfinities = 0;
  for (int i = 0; i < solution.size(); i++)
  {
      sumOfAfinities += matrix[solution[i].first][solution[i].second];
  }
  return sumOfAfinities / solution.size();
}

std::vector<int> Matriz::getNodes() {
  std::vector<int> result;
  for(int i = 0; i < this->get_rows(); i++) {
    result.push_back(i);
  }
  return result;
}