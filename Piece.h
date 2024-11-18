#ifndef PIECE_H
#define PIECE_H
#include <vector>
#include <algorithm>
#include "Point.h"

class PuzzlePiece {
public:
  PuzzlePiece() {};
  ~PuzzlePiece() {};

  void setAnchor(Point p) {
    anchor = p;
  }

  PuzzlePiece rotate() {
    std::for_each(points.begin(), points.end(), [](Point &p) { p = p.rotate(); });
    return *this;
  }

  PuzzlePiece mirror() {
    std::for_each(points.begin(), points.end(), [](Point &p) { p = p.mirror(); });
    return *this;
  }

  std::vector<Point> body(Point anchor) {
    std::vector<Point> body = { anchor };
    for (Point p : points) {
      body.push_back(p + anchor);
    }
    return body;
  }

  std::vector<Point> body() {
    std::vector<Point> body = { anchor };
    for (Point p : points) {
      body.push_back(p + anchor);
    }
    return body;
  }

  void print() {
    int h = 0;
    for (Point p : body()) {
      if (h != p.getY()) {
        std::cout << std::endl;
        h = p.getY();
      }
      p.print();
      std::cout << " ";
    }
  }

  void printOneLine() {
    for (Point p : body()) {
      p.print();
      std::cout << " ";
    }
    std::cout << std::endl;
  }

  char getName() {
    return name;
  }

protected:
  Point anchor = Point(0, 0);
  std::vector<Point> points;
  char name;
  
};

class JPiece : public PuzzlePiece {
public:
  JPiece() {
    points = { Point(0, 1), Point(0, 2), Point(0, 3), Point(1, 0) };
    name = 'J';
  }
};

class PPiece : public PuzzlePiece {
public:
  PPiece() {
    points = { Point(0,1), Point(0, -1), Point(1, 1), Point(1, 0) };
    name = 'P';
  }
};

class UPiece : public PuzzlePiece {
public:
  UPiece() {
    points = { Point(-1, 0), Point(-1, 1), Point(1, 0), Point(1, 1) };
    name = 'U';
  }
};

class TPiece : public PuzzlePiece {
public:
  TPiece() {
    points = { Point(0, 1), Point(0, -1), Point(0, -2), Point(1, 0) };
    name = 'T';
  }
};

class LPiece : public PuzzlePiece {
public:
  LPiece() {
    points = { Point(0, 1), Point(0, 2), Point(1, 0), Point(2, 0) };
    name = 'L';
  }
};

class SPiece : public PuzzlePiece {
public:
  SPiece() {
    points = { Point(0, 1), Point(1, 1), Point(-1, 0), Point(-2, 0) };
    name = 'S';
  }
};

class OPiece : public PuzzlePiece {
public:
  OPiece() {
    points = { Point(1, 0), Point(1, 1), Point(1, -1), Point(0, 1), Point(0, -1) };
    name = 'O';
  }
};

class ZPiece : public PuzzlePiece {
public:
  ZPiece() {
    points = { Point(-1, 1), Point(0, 1), Point(0, -1), Point(1, -1) };
    name = 'Z';
  }
};
#endif // PIECE_H