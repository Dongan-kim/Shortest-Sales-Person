#ifndef _TSP_SOLVER_HPP
#define _TSP_SOLVER_HPP

#include <iostream>
#include "listofpoints.hpp"
#include "tspcycle.hpp"

// the class implement the TSP solver
class TSPSolver : public ListOfPoints
{
  private:  
  // may hold the following members:
  ListOfPoints m_list;  // store the original list.
  ListOfPoints list_frst3;  // store the solution list.
  float solution; // store the shortest length.


  public:
    TSPSolver(ListOfPoints &list);
    void solve();
    void printSolution();
    void getSolution();
};

#endif
