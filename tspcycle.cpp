#include <iostream>
#include "listofpoints.hpp"
#include "tspcycle.hpp"
#include "tspsolver.hpp"
#include "point.hpp"
#include "LLnode.hpp"


TSPCycle::TSPCycle() {
  cout << "default TSPCycle constructor" << endl;
}

float TSPCycle::getDistance2(LLnode* n, LLnode* n2) const{
  float x_dis = n->getData() - ((n->getNext())->getData());
  float y_dis = n2->getData() - ((n2->getNext())->getData2());

  float d = sqrt(x_dis*x_dis + y_dis*y_dis);

  return d;
}

// returns the length of the cycle
float TSPCycle::getLength() const {
  LLnode* h1 = l.getHead(); 
  if(h1 == NULL || h1->getNext() == NULL)
    return 0;
  
  float length = 0;

  //Iterate through linked list(which is now in the correct order) and find the length
  //between each point that next to one another. Add the length to total length.
  l.getHead();
  while(h1->getNext()){

    length = length + getDistance2(h1, h1->getNext());
    h1 = h1->getNext();
  }

  LLnode* t1 = l.getHead();
  LLnode* t2 = l.getHead2();
  int fp = t1->getData();
  int fp2 = t2->getData2();
  Point FirstP(fp, fp2, "First");
  while(t1->getNext()!= NULL){
    t1 = t1->getNext();
    t2 = t2->getNext();
  }
  int lp = t1->getData();
  int lp2 = t2->getData2();
  Point LastP(lp, lp2, "Lastpoint");
  //find length between last point and first point
  length = length + FirstP.getDistance(LastP);

  return length;
}


