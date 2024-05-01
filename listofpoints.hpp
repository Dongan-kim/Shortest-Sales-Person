#ifndef _LIST_OF_POINT_HPP
#define _LIST_OF_POINT_HPP

#include <iostream>
#include <vector>

#include "point.hpp"
#include "LLnode.hpp"
using namespace std;

#define MAX_X 20
#define MAX_Y 20

// the class stores an ordered list of points
// used to store the input to the problem
// may be also used to store a partial solution to the TSP problem
class ListOfPoints : public Point
{
  //protected: //  children of the class can access the protected data fields
    // currently m_points stores the points in a vector 
    // but you may decide to use a different container. Up to you
    //std::vector<Point> m_points;

  public:
    ListOfPoints();
    

    // adds a new point after a point with the given name in the list
    void addAfter(LLnode* prev_node, LLnode* prev_node2, LLnode* prev_node3, Point& newPt);
    
    //remove a node after head
    LLnode* removeAfter(LLnode* head);

    // adds a new point to the end of the list
    void addPoint(Point& newPt);
    
    // gets a point from the list at index i
    Point& getPointAt(unsigned int i);

    // gets the size of the list
    int getSize() const;

    // prints the list of points
    void printList() const;
    
    // draws the points
    void draw() const;
    
    // get head of x point
    LLnode* getHead() const;
    
    // get head of y point
    LLnode* getHead2() const;
    
    // get head of name
    LLnode* getHead3() const;

private:
	  LLnode* head;
    LLnode* head2;
    LLnode* head3;
    LLnode* tail;
    LLnode* tail2;
    LLnode* tail3;
    int size;
};

#endif
