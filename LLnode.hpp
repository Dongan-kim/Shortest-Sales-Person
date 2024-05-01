#ifndef LL_NODE_HPP
#define LL_NODE_HPP
#include <iostream>
#include "point.hpp"
#include "listofpoints.hpp"
using namespace std;

class LLnode 
{
  public:

    // defualt constructor
    LLnode() {
        //cout << "default constructor for LLnode" << endl;
        //setData(0);
        //setNext(NULL);
    }

    // get node
    LLnode* getNext() {
        return next;
    }

    // set node
    void setNext(LLnode* next_node) {
        next = next_node;
    }

    // get data
    int getData() {
        return data;
    }
    
    int getData2() {
        return data2;
    }

    string getData3() {
        return data3;
    }

    // set data
    void setData(Point& newPt) {
        data = newPt.getX();
    }
    void setData2(Point& newPt) {
        data2 = newPt.getY();
    }

    void setData3(Point& newPt) {
        data3 = newPt.getName();
    }

  ~LLnode() {
    
   }

  private:
	  int data;
      int data2;
      string data3;
	  LLnode* next;
};

#endif
