#include "../include/matrix.hpp"
#include "../include/greedyAlgorithm.hpp"
#include "../include/2ndGreedyAlgorithm.hpp"
#include "../include/grasp.hpp"
#include "../include/multiStart.hpp"
#include "../include/vns.hpp"
#include <chrono>

int main(int argc, char *argv[])
{
  if (argc == 1)
  {
    std::cerr << "Necesitas introducir el nombre del fichero que quieras (El fichero tiene que estar en la carpeta txt\n";
  }
  else
  {
    srand(time(NULL));

    std::string dir("../txt/");
    std::string name(argv[1]);
    std::string namefile = dir + name;

    Matriz a(namefile);
    greedyAlgorithm greedy(namefile);
    secondGreedyAlgorithm greedy2(namefile);
    Grasp grasp(namefile, 1000, 100, false);
    MultiStart ms(namefile, 1000, 100, false);
    Vns vns(namefile, 1000, 100, false, 1000);
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    std::vector<int> solutiongreedy = greedy.execute();
    end = std::chrono::system_clock::now();
    int greedy_time = std::chrono::duration_cast<std::chrono::microseconds> (end-start).count();

    start = std::chrono::system_clock::now();
    std::vector<int> solutiongreedy2 = greedy2.execute();
    end = std::chrono::system_clock::now();
    int greedy2_time = std::chrono::duration_cast<std::chrono::microseconds> (end-start).count();

    start = std::chrono::system_clock::now();
    std::vector<int> solutiongrasp = grasp.execute();
    end = std::chrono::system_clock::now();
    int grasp_time = std::chrono::duration_cast<std::chrono::microseconds> (end-start).count();

    start = std::chrono::system_clock::now();
    std::vector<int> solutionms = ms.execute();
    end = std::chrono::system_clock::now();
    int ms_time = std::chrono::duration_cast<std::chrono::microseconds> (end-start).count();

    start = std::chrono::system_clock::now();
    std::vector<int> solutionvns = vns.execute();
    end = std::chrono::system_clock::now();
    int vns_time = std::chrono::duration_cast<std::chrono::microseconds> (end-start).count();

    std::cout << "Solución greedy";
    std::cout << std::endl;
    for (int i = 0; i < solutiongreedy.size(); i++)
    {
      std::cout << solutiongreedy[i] << " ";
    }
    std::cout << std::endl
              << a.getMd(solutiongreedy) << " Se ha ejecutado por: " << greedy_time << " microsegundos" << std::endl;
    std::cout << std::endl;

    std::cout << "Solución greedy2";
    std::cout << std::endl;
    for (int i = 0; i < solutiongreedy2.size(); i++)
    {
      std::cout << solutiongreedy2[i] << " ";
    }
     std::cout << std::endl
              << a.getMd(solutiongreedy2) << " Se ha ejecutado por: " << greedy2_time << " microsegundos" << std::endl;
    std::cout << std::endl;

    std::cout << "Solución grasp";
    std::cout << std::endl;
    for (int i = 0; i < solutiongrasp.size(); i++)
    {
      std::cout << solutiongrasp[i] << " ";
    }
     std::cout << std::endl
              << a.getMd(solutiongrasp) << " Se ha ejecutado por: " << grasp_time << " microsegundos" << std::endl;
    std::cout << std::endl;

    std::cout << "Solución multistart";
    std::cout << std::endl;
    for (int i = 0; i < solutionms.size(); i++)
    {
      std::cout << solutionms[i] << " ";
    }

     std::cout << std::endl
              << a.getMd(solutionms) << " Se ha ejecutado por: " << ms_time << " microsegundos" << std::endl;
    std::cout << std::endl;
    
    std::cout << "Solución vns";
    std::cout << std::endl;
    for (int i = 0; i < solutionvns.size(); i++)
    {
      std::cout << solutionvns[i] << " ";
    }

     std::cout << std::endl
              << a.getMd(solutionvns) << " Se ha ejecutado por: " << vns_time << " microsegundos" << std::endl;
    std::cout << std::endl;
  }
}
