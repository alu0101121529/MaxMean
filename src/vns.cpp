#include "../include/vns.hpp"

std::vector<int> Vns::constructionPhase(std::vector<int> firstCandidates, int solutionSize)
{
  std::vector<int> solution;
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

std::vector<int> Vns::constructNeighborhood(int solSize, std::vector<int> firstCandidates, int addSize)
{
  int sz = (rand() % 2 == 1) ? solSize + addSize : solSize - addSize;
  sz = (sz < 1) ? solSize + addSize : sz;
  sz = (sz > firstCandidates.size()) ? solSize - addSize : sz;
  // si k es muy elevado para el numero de nodos puede ocurrir esto
  sz = (sz < 1) ? 1 : sz;
  sz = (sz < 2) ? firstCandidates.size() : sz;
  return constructionPhase(firstCandidates, sz);
}

std::vector<int> Vns::localSearch(std::vector<int> solution, std::vector<int> firstCandidates)
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

std::pair<int, bool> Vns::getWorstMd(std::vector<int> solution)
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

std::vector<int> Vns::execute()
{
  std::vector<int> firstNodes = graph.getNodes();
  int solutionSize = (rand() % (graph.get_rows() - 2)) + 2;
  std::vector<int> firstSolution = constructionPhase(firstNodes, solutionSize);
  std::vector<int> bestSol = localSearch(firstSolution, firstNodes);
  float bestDistance = graph.getMd(firstSolution);
  int iterations = 0;
  int noImprovement = 0;
  int sz = 1;
  while (iterations < this->Iterations && noImprovement < this->NoImprov)
  {
    iterations++;
    sz = 1;
    while (sz < szTotal)
    {
      std::vector<int> initialSol = constructNeighborhood(solutionSize, firstNodes, sz);
      std::vector<int> localSearchVector = localSearch(initialSol, firstNodes);
      float testMd = graph.getMd(localSearchVector);
      if (testMd > bestDistance)
      {
        bestSol = localSearchVector;
        bestDistance = testMd;
        sz = 1;
        noImprovement = 0;
      }
      else
      {
        noImprovement++;
        sz++;
      }
    }
  }

  return bestSol;
}