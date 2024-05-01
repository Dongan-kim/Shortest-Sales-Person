#ifndef _TSP_CYCLE_HPP
#define _TSP_CYCLE_HPP

#include <iostream>

#include "listofpoints.hpp"
#include "tspsolver.hpp"
#include "LLnode.hpp"

// the class stores a cycle that traverses all points in some order
// it is used to store the solution to the problem
// it is a subclass of ListOfPoints
class TSPCycle 
  :public ListOfPoints
{

  public:
    ListOfPoints l;
    // default constructor
    TSPCycle();
    
    float getDistance2(LLnode* n, LLnode* n2) const;
    // returns the length of the cycle
    float getLength() const;

};

#endif

