#include <iostream>
#include "listofpoints.hpp"
#include "tspcycle.hpp"
#include "tspsolver.hpp"
#include "point.hpp"

float Point::getDistance(const Point &other) const { 
  float x_dis = other.getX() - this->getX();

  float y_dis = other.getY() - this->getY();

  float d = sqrt(x_dis*x_dis + y_dis*y_dis);

  return d;
}

string Point::toString() const {
  // examples how to create string from small parts
  string str(m_name);
  str += " = (";
  str += std::to_string(m_x);
  str.append(",").append(std::to_string(m_y)).append(")");
  return str;
}


void Point::printPoint() const {
  cout << toString() << endl;
}

// used for printing Point using << operator.
// For example, the following code will work
// Point origin(0,0,'O');
// cout << origin;
ostream& operator<<(ostream &os, const Point &p) {
  return os << p.toString();
}
