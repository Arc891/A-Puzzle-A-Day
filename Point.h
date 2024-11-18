#ifndef POINT_H
#define POINT_H
#include <iostream>

class Point {
public:
  Point() : x(-1), y(-1) {};
  Point(int x, int y) : x(x), y(y) {};
  
  ~Point() {};
  
  int getX() const { return x; }
  int getY() const { return y; }
  
  void print() { std::cout << "(" << x << ", " << y << ")"; }
  
  Point rotate() { return Point(y, -x); }
  Point mirror() { return Point(-x, y); }
  
  Point operator +  (const Point& p) { return Point(x + p.x, y + p.y); }
  Point operator -  (const Point& p) { return Point(x - p.x, y - p.y); }
  Point operator += (const Point& p) { x += p.x; y += p.y; return *this; }
  Point operator -= (const Point& p) { x -= p.x; y -= p.y; return *this; }
  bool  operator == (const Point& p) const { return x == p.x && y == p.y; }
  bool  operator != (const Point& p) const { return !(*this == p); }

private:
  int x;
  int y;
};

#endif