#include "../include/greedyAlgorithm.hpp"

std::vector<int> greedyAlgorithm::execute()
{
  std::vector<int> solution;
  std::pair<int, int> firstSolutionPair = graph.biggestAfinityPair();
  solution.push_back(firstSolutionPair.first);
  solution.push_back(firstSolutionPair.second);
  std::pair<int, bool> k = maximizeMd(solution);
  while (k.second)
  {
    solution.push_back(k.first);
    k = maximizeMd(solution);
  }
  return solution;
}

std::pair<int, bool> greedyAlgorithm::maximizeMd(std::vector<int> solution)
{
  std::vector<std::pair<int, bool>> vertexVector;
  std::pair<int, bool> vertex(-1, false);
  vertexVector.push_back(vertex);
  float currentDistance = graph.getMd(solution);
  for (int i = 0; i < graph.get_rows(); i++)
  {
    if (!(std::find(solution.begin(), solution.end(), i) != solution.end()))
    {
      solution.push_back(i);
      float nextMd = graph.getMd(solution);
      solution.pop_back();
      if (nextMd > currentDistance)
      {
        currentDistance = nextMd;
        vertexVector.clear();
        vertexVector.push_back(std::pair<int, bool>(i, true));
      }
      else if (nextMd == currentDistance)
      {
        vertexVector.push_back(std::pair<int, bool>(i, true));
      }
    }
  }
  return vertexVector[rand() % vertexVector.size()];
}