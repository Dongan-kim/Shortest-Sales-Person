#include <iostream>
#include "listofpoints.hpp"
#include "tspcycle.hpp"
#include "tspsolver.hpp"
#include "point.hpp"

TSPSolver::TSPSolver(ListOfPoints &list){
  m_list = list; //move all the points to m_list


  LLnode* n = list.getHead();
  LLnode* n2 = list.getHead2();
  LLnode* n3 = list.getHead3();
  int i=0;
  //store first three points to list_first3 from original list.
  while(i<3){  
  int a = n->getData();
  int b = n2->getData2();
  string c = n3->getData3();
  Point q(a,b,c);

  list_frst3.addPoint(q);
  n = n->getNext();
  n2 = n2->getNext();
  n3 = n3->getNext();
  i++;
 }
}

void TSPSolver::solve() {
  LLnode* n = m_list.getHead();
  
  int sizeOfsub = 3; // store size of solution list.
  //count the number of nodes in linked list.
  int count = 0;
  while(n){
  count++;
  n = n->getNext();
  }

  LLnode* b = m_list.getHead(); // for iterate the original list.
  LLnode* b2 = m_list.getHead2();
  LLnode* b3 = m_list.getHead3();
  int j =0;
  while(j<3){
    b = b->getNext(); //move head to 4th position for taking out the point and inserting.
    b2 = b2->getNext();
    b3 = b3->getNext();
    j++;
  }

  //iterate original list from 4th position and taking out point and insert each position to solution list.
  while(b!=NULL){  
  float shortest = 0;      // store shortest length
  int shortestindex = 0;   // store index position where the route will be shortest
  float total = 0;         // store total cycle length
  int index = 1;           // store index position for solution list
  LLnode* a = list_frst3.getHead();
  LLnode* a2 = list_frst3.getHead2();
  LLnode* a3 = list_frst3.getHead3();
  LLnode* track_b;         
  LLnode* track_b2;
  LLnode* track_b3;

  int tmp = b->getData();
  int tmp2 = b2->getData2();
  string tmp3 = b3->getData3();
  Point tmp_p(tmp,tmp2,tmp3); // Point that will insert to solution list.

  LLnode* f = list_frst3.getHead(); // for iterate solution list.
  LLnode* f2 = list_frst3.getHead2();
  LLnode* f3 = list_frst3.getHead3();

  // calculate length for every position and find out which one is shortest.
  while(a!=NULL){  //iterate solution list.
     total = 0;
     int k=0;
     list_frst3.addAfter(a,a2,a3,tmp_p); //insert tmp_p
     // calculate total length by add up distance between next each other point.
     while(k<sizeOfsub+1){  
     if(f->getNext() == NULL){   // calculate distance between last point and start point.
      track_b = list_frst3.getHead();
      track_b2 = list_frst3.getHead2();
      track_b3 = list_frst3.getHead3();
      int track = track_b->getData();
      int track2 = track_b2->getData2();
      string track3 = track_b3->getData3();
      Point Next(track,track2,track3);
      int next_a = f->getData();
      int next_a2 = f2->getData2();
      string next_a3 = f3->getData3();
      Point A(next_a,next_a2,next_a3);
      total = total + A.getDistance(Next);
    }else{                      //calculate distance between next each other point.
    track_b = f->getNext();
    track_b2 = f2->getNext();
    track_b3 = f3->getNext();
    int next_a = f->getData();
    int next_a2 = f2->getData2();
    string next_a3 = f3->getData3();
    int track = track_b->getData();
    int track2 = track_b2->getData2();
    string track3 = track_b3->getData3();
    Point A(next_a,next_a2,next_a3);
    Point Next(track,track2,track3);
    total = total + A.getDistance(Next);
    }
    f = f->getNext();
    f2 = f2->getNext();
    f3 = f3->getNext();
    k++;
    }
    if(total <= shortest || shortest == 0){ 
      shortest = total;                     //update shortest length
      shortestindex = index;                //update index position where will be shortest
    }
    removeAfter(a);       //remove a node once that inserted.
    removeAfter(a2);
    removeAfter(a3);
    index++;
    a = a->getNext();
    a2 = a2->getNext();
    a3 = a3->getNext();
    f = list_frst3.getHead();
    f2 = list_frst3.getHead2();
    f3 = list_frst3.getHead3();
  }
 
  LLnode* g = list_frst3.getHead();
  LLnode* g2 = list_frst3.getHead2();
  LLnode* g3 = list_frst3.getHead3();
  int k = 0;
  while(k<shortestindex-1){         // making solution list.
  g = g->getNext();
  g2 = g2->getNext();
  g3 = g3->getNext();
  k++;
  }
  list_frst3.addAfter(g,g2,g3,tmp_p); // insert tmp_p at index where the list will be shortest.
  sizeOfsub++;
  b = b->getNext();
  b2 = b2->getNext();
  b3 = b3->getNext();
  solution = shortest;      // store shortest length to solution 
  }
  list_frst3.printList();   // print solution point
}

// printout solution.
void TSPSolver::getSolution(){
  cout << solution;
}


