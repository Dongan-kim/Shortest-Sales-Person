#include <iostream>
#include <cstdlib>

#include "point.hpp"
#include "listofpoints.hpp"
#include "tspsolver.hpp"
#include "tspcycle.hpp"

using namespace std;

void testPoint() {
  Point origin(4,5,"ORIGIN");
  cout << "--print using printPoint():" << endl;
  origin.printPoint();
  cout << "--print using toString():" << endl;
  cout << origin.toString() << endl;
  cout << "--print using << operator:" << endl;
  cout << origin << endl;
  

  Point q(6,7,"Q");
 
  cout << "distance between ORIGIN and Q is " << q.getDistance(origin) << endl;

}



void testSolver(ListOfPoints &input) {
  cout << "---run the solver---" << endl;
  TSPSolver solver(input);
  cout << "Solution found is: " << endl;
  solver.solve();
  cout << "the length of the solution is: ";
  solver.getSolution();
  cout << endl;
}

void test1() {
  Point p[4] = {Point(2,2,"A"),
                Point(2,6,"B"),
                Point(5,6,"C"),
                Point(5,9,"D")};

  cout << "Creating a list of points:" << endl;
  ListOfPoints inputTSP;
  for (int i=0;i<4;i++)
    inputTSP.addPoint(p[i]);
  
  cout << "Printing the list:" << endl;
  inputTSP.printList();  
  inputTSP.draw();

  testSolver(inputTSP);
}


void test2() {
  Point p[11] = {Point(1,1,"A"),
                Point(6,1,"B"),
                Point(8,1,"C"),
                Point(10,1,"D"),
                Point(3,3,"E"),
                Point(6,3,"F"),
                Point(1,4,"G"),
                Point(5,4,"H"),
                Point(8,4,"I"),
                Point(3,7,"J"),
                Point(6,7,"K"),};

  cout << "Creating a list of points:" << endl;
  ListOfPoints inputTSP;
  for (int i=0;i<11;i++)
    inputTSP.addPoint(p[i]);
  
  cout << "Printing the list:" << endl;
  inputTSP.printList();  
  inputTSP.draw();  

  testSolver(inputTSP);
}


void test3() {
  Point p[4] = {Point(1,1,"A"),
                Point(6,1,"B"),
                Point(8,1,"C"),
                Point(10,1,"D"),};

  cout << "Creating a list of points:" << endl;
  ListOfPoints inputTSP;
  for (int i=0;i<4;i++)
    inputTSP.addPoint(p[i]);
  
  cout << "Printing the list:" << endl;
  inputTSP.printList();  
  inputTSP.draw();  

  testSolver(inputTSP);
}

void test4() {
ListOfPoints inputTSP;
  Point p(0,0,"O");
  cout << "Creating a list of points:" << endl;

  for (int i=0;i<21;i++) {
    string s;
    s = 'A' + i;
    p = Point(i,i,s);
    inputTSP.addPoint(p);
  }
  cout << "Printing the list:" << endl;
  inputTSP.printList();  
  inputTSP.draw(); 
  testSolver(inputTSP);
}

/*void test5() {
  ListOfPoints inputTSP;
  Point p(0,0,"O");
  cout << "Creating a list of points:" << endl;

  for (int i=0;i<50;i++) {
    p = Point(rand() % 1000, rand() % 1000,"P"+to_string(i));
    inputTSP.addPoint(p);
  }

  testSolver(inputTSP);
}*/

void test6() {
  Point p[11] = {Point(7,1,"A"),
                Point(2,1,"B"),
                Point(8,5,"C"),
                Point(10,3,"D"),
                Point(3,1,"E"),
                Point(4,3,"F"),
                Point(2,4,"G"),
                Point(9,4,"H"),
                Point(8,8,"I"),
                Point(3,2,"J"),
                Point(6,9,"K"),};

  cout << "Creating a list of points:" << endl;
  ListOfPoints inputTSP;
  for (int i=0;i<11;i++)
    inputTSP.addPoint(p[i]);
  
  cout << "Printing the list:" << endl;
  inputTSP.printList();  
  inputTSP.draw();  

  testSolver(inputTSP);
}

void test7() {
  Point p[7] = {Point(1,1,"A"),
                Point(5,1,"B"),
                Point(5,5,"C"),
                Point(1,5,"D"),
                Point(3,3,"E"),
                Point(7,3,"F"),
                Point(3,7,"G"),};

  cout << "Creating a list of points:" << endl;
  ListOfPoints inputTSP;
  for (int i=0;i<7;i++)
    inputTSP.addPoint(p[i]);
  
  cout << "Printing the list:" << endl;
  inputTSP.printList();  
  inputTSP.draw();  

  testSolver(inputTSP);
}


int main() {

  cout << "****Test point**" << endl;
  testPoint();
  cout << "****End of test point**" << endl << endl;

  cout << "****test1**:" << endl;
  test1();
  cout << "****end of test1**:" << endl << endl;
 
  cout << "****test2**:" << endl;
  test2();
  cout << "****end of test2**:" << endl << endl;
  
 
  cout << "****test3**:" << endl;
  test3();
  cout << "****end of test3**:" << endl << endl;

  cout << "****test4**:" << endl;
  test4();
  cout << "****end of test4**:" << endl << endl;

  /*cout << "****test5**:" << endl;
  test5();
  cout << "****end of test5**:" << endl << endl;
  */

  cout << "****test4**:" << endl;
  test6();
  cout << "****end of test4**:" << endl << endl;

  cout << "****test4**:" << endl;
  test7();
  cout << "****end of test4**:" << endl << endl;

  return 0;
}
