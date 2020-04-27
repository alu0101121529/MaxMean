#include "../include/multistart.hpp"

std::vector<int> MultiStart::constructionPhase(std::vector<int> firstCandidates)
{
  std::vector<int> solution;
  int firstNode = rand() % firstCandidates.size();
  solution.push_back(firstCandidates[firstNode]);
  int solutionSize = (rand() % (graph.get_rows() - 2)) + 2;
  while (solution.size() < solutionSize)
  {
    int randomSelection = rand() % firstCandidates.size();
    if (std::find(solution.begin(), solution.end(), firstCandidates[randomSelection]) == solution.end())
    {
      solution.push_back(randomSelection);
    }
  }
  return solution;
}

std::vector<int> MultiStart::RCL(std::vector<int> solution, std::vector<int> firstCandidates)
{
  std::vector<int> sortedNodes;
  std::vector<float> sortedDistances;
  std::vector<int> rclVector;
  for (int i = 0; i < firstCandidates.size(); i++)
  {
    if (std::find(solution.begin(), solution.end(), firstCandidates[i]) == solution.end())
    {
      solution.push_back(firstCandidates[i]);
      float testMd = graph.getMd(solution);
      solution.pop_back();
      int position = 0;
      for (int j = 0; j < sortedDistances.size(); j++)
      {
        if (testMd < sortedDistances[j])
        {
          position++;
        }
      }
      sortedDistances.insert(sortedDistances.begin() + position, testMd);
      sortedNodes.insert(sortedNodes.begin() + position, firstCandidates[i]);
    }
  }
  int percent = (sortedNodes.size() / (1 / 0.2));
  percent = percent == 0 ? 1 : percent;
  std::copy(sortedNodes.begin(), sortedNodes.begin() + percent, std::back_inserter(rclVector));
  return rclVector;
}

std::vector<int> MultiStart::localSearch(std::vector<int> solution, std::vector<int> firstCandidates)
{
  bool improvement = true;
  while (improvement)
  {
    improvement = false;
    std::pair<int, bool> worst = getWorstMd(solution);
    if (worst.second)
    {
      improvement = true;
      solution.erase(solution.begin() + worst.first);
    }
  }
  return solution;
}

std::pair<int, bool> MultiStart::getWorstMd(std::vector<int> solution)
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
      if (anxious)
      {
        return std::pair<int, bool>(i, true);
        ;
      }
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

std::vector<int> MultiStart::execute()
{
  std::vector<int> firstNodes = graph.getNodes();
  std::vector<int> bestSolution;
  bestSolution.push_back(0);
  float bestDistance = graph.getMd(bestSolution);
  int iterations = 0;
  int noImprovement = 0;
  while (iterations < this->Iterations && noImprovement < this->NoImprov)
  {
    iterations++;
    std::vector<int> initialSol = constructionPhase(firstNodes);
    std::vector<int> localSearchVector = localSearch(initialSol, firstNodes);
    float testMd = graph.getMd(localSearchVector);
    if (testMd > bestDistance)
    {
      bestSolution = localSearchVector;
      bestDistance = testMd;
      noImprovement = 0;
    }
    else
    {
      noImprovement++;
    }
  }

  return bestSolution;
}