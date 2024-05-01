#include <iostream>
#include "listofpoints.hpp"
#include "LLnode.hpp"
using namespace std;

ListOfPoints::ListOfPoints() {
  //cout << "creating a new list" << endl;
  //make 3 Linked List for x point, y point and name.
  head = NULL;
  head2 = NULL;
  head3 = NULL;
  tail = NULL;
  tail2 = NULL;
  tail3 = NULL;
  size = 0;
}

LLnode* ListOfPoints::removeAfter(LLnode* head) {
  LLnode* ptr = head;

  LLnode* prev = NULL;
  
    prev = ptr;

    ptr = prev->getNext();
  
    if(ptr->getNext() == NULL){
      delete(prev->getNext());
      prev->setNext(NULL);
      size--;
    }else{
    delete(prev->getNext());
    prev->setNext(ptr->getNext());
    size--;
    }
    return head;
}
void ListOfPoints::addAfter(LLnode* prev_node, LLnode* prev_node2, LLnode* prev_node3, Point& newPt) {
  LLnode* n = new LLnode();
  LLnode* n2 = new LLnode();
  LLnode* n3 = new LLnode();
  
  n->setData(newPt);
  n2->setData2(newPt);
  n3->setData3(newPt);
  n->setNext(prev_node->getNext());
  n2->setNext(prev_node2->getNext());
  n3->setNext(prev_node3->getNext());
  (prev_node->setNext(n));
  (prev_node2->setNext(n2));
  (prev_node3->setNext(n3));
  size++;
}

void ListOfPoints::addPoint(Point& newPt)  {
  LLnode* n = new LLnode();       //for x point 
  LLnode* n2 = new LLnode();      //for y point 
  LLnode* n3 = new LLnode();      //for name
  n->setData(newPt);
  n2->setData2(newPt);
  n3->setData3(newPt);
  n->setNext(tail);
  n2->setNext(tail2);
  n3->setNext(tail3);
  if(head==NULL){
  head = n;
  head2 = n2;
  head3 = n3;
  }else{
   LLnode* tmp = head;
   LLnode* tmp2 = head2;
   LLnode* tmp3 = head3;
   while(tmp->getNext()!=NULL){
     tmp = tmp->getNext();
     tmp2 = tmp2->getNext();
     tmp3 = tmp3->getNext();
   }
   tmp->setNext(n);
   tmp2->setNext(n2);
   tmp3->setNext(n3);
  }
  size++;
}

int ListOfPoints::getSize() const {
  return size;
}

void ListOfPoints::printList() const {
  LLnode* n = head;     // x point 
  LLnode* n2 = head2;   // y point
  LLnode* n3 = head3;   // name
    while(n){
    cout << n3->getData3() << " = " << "(" << n->getData() << "," << n2->getData2() << ")" << endl;
    n = n->getNext();
    n2 = n2->getNext();
    n3 = n3->getNext();
    }
}

void ListOfPoints::draw() const {
  cout << "drawing the points..." << endl;

  if(head == NULL)
    cout << "list is empty..." << endl;
  else{
    LLnode* n = head;
    LLnode* n2 = head2;

  //find the min and max value for x and y out of all the points
  int x_min = n->getData();
  int x_max = n->getData();

  int y_min = n2->getData2();
  int y_max = n2->getData2();

  while(n!=NULL){
    if(n->getData() < x_min){
      x_min = n->getData();

    }else if(n->getData() > x_max){
        x_max = n->getData();

    }else if(n2->getData2() < y_min){
        y_min = n2->getData2();

    }else{
        y_max = n2->getData2();

        n = n->getNext();
        n2 = n2->getNext();
    }
  }

  //each point is between 0 and 20 so set rows and
  //cols equal to max
  int rows= 20;
  int cols = 20;

  char draw_graph[rows][cols];//initialize 2d array

  //fill array with -'s
  for(int i = 0; i < rows; i++){
    for(int j = 0; j< cols; j++)
    {
      draw_graph[i][j] = '-';
    }
  }

  //iterate through linked list and insert the letter corresponding to the point
  //into the 2d array at the correct index. 
  n = head;
  n2 = head2;
  LLnode* n3 = head3;
  while(n!=NULL){
      draw_graph[(rows-1)-(n2->getData2())][n->getData()] = n3->getData3()[0];
      n = n->getNext();
      n2 = n2->getNext();
      n3 = n3->getNext();
  }
  //print the relevant portion of the graph
  n= head;
  n2 = head2;
  n3 = head3;
  for(int i = rows-(20); i < rows; i++){
    for(int j = 0; j<20; j++){
        cout << draw_graph[i][j];
      }
    printf("\n");
  }
}
}

LLnode* ListOfPoints::getHead() const {
  return head;
}

LLnode* ListOfPoints::getHead2() const {
  return head2;
}

LLnode* ListOfPoints::getHead3() const {
  return head3;
}