#include "../include/2ndGreedyAlgorithm.hpp"

std::vector<int> secondGreedyAlgorithm::execute()
{
  std::vector<int> solution = graph.getNodes();
  std::pair<int, bool> k = maximizeMd(solution);
  while (k.second)
  {
    solution.erase(solution.begin() + k.first);
    k = maximizeMd(solution);
  }
  return solution;
}

std::pair<int, bool> secondGreedyAlgorithm::worstMd(std::vector<int> solution)
{
  std::vector<std::pair<int, bool>> vertexVector;
  std::pair<int, bool> vertex(-1, false);
  vertexVector.push_back(vertex);
  float currentDistance = graph.getMd(solution);
  float currentEdgeSum = currentDistance * solution.size();
  for (int i = 0; i < solution.size(); i++)
  {
    int vertex = solution[i];
    solution.erase(solution.begin() + i);
    float nextMd = graph.getMd(solution);
    solution.insert(solution.begin() + i, vertex);
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
  return vertexVector[rand() % vertexVector.size()];
}