#ifndef _TSP_CYCLE_HPP
#define _TSP_CYCLE_HPP

#include <iostream>

#include "listofpoints.hpp"
#include "tspsolver.hpp"

using namespace std;

// the class stores a cycle that traverses all points in some order
// it is used to store the solution to the problem
// it is a subclass of ListOfPoints
class TSPCycle : public ListOfPoints {

  public:
    TSPCycle()     {
      cout << "default TSPCycle constructor" << endl;
    }

    float getLength();

};

#endif