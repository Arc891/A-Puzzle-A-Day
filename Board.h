#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>
#include <algorithm>
#include "Point.h"
#include "Piece.h"

class Board {
public:
  Board() : Board(11, 18) {};
  Board(int month, int day) {
    // Create a specific board that is 7x7, but does not contain (6,0), (6,1), (3,6), (4,6), (5,6), (6,6)
    std::vector<Point> skip = { Point(6, 0), Point(6, 1), Point(3, 6), Point(4, 6), Point(5, 6), Point(6, 6) };
    for (int y = 0; y < 7; y++) {
      for (int x = 0; x < 7; x++) {
        Point p(x, y);
        if (std::find(skip.begin(), skip.end(), p) == skip.end()) {
          points.push_back(p);
        }
      }
    }
    covered.push_back(points.at(month - 1));
    covered.push_back(points.at(day - 1 + 12));
  };
  
  ~Board() {};

  void printPoints(bool showCoordinates = false) {
    int h = 0;
    for (Point p : points) {
      if (h != p.getY()) {
        std::cout << std::endl;
        h = p.getY();
      }
      if (std::find(covered.begin(), covered.end(), p) != covered.end()) {
        std::cout << "X";
      } else {
        std::cout << "O";
      }
      if (showCoordinates) {
        p.print();
      }
      std::cout << " ";
    }
    std::cout << std::endl;
  };
  
  void printCovered() {
    for (Point p : covered) {
      p.print();
      std::cout << " ";
    }
  };

  bool pointInVec(Point p, std::vector<Point> vec) {
    for (Point b : vec) {
      if (b == p) {
        return true;
      }
    }
    return false;
  }

  bool isValidPoint(Point p) {
    return pointInVec(p, points);
  }

  bool canPlacePiece(PuzzlePiece *piece, Point p) {
    for (Point b : piece->body(p)) {
      if (pointInVec(b, covered) || !isValidPoint(b)) {
        return false;
      }
    }
    return true;
  }

  void placePiece(PuzzlePiece *piece, Point p) {
    for (Point b : piece->body(p)) {
      covered.push_back(b);
    }
  }

  std::vector<Point> getPoints() { return points; }
  std::vector<Point> getCovered() { return covered; }

  std::vector<Point> getFree() {
    std::vector<Point> free;
    for (Point p : points) {
      if (std::find(covered.begin(), covered.end(), p) == covered.end()) {
        free.push_back(p);
      }
    }
    return free;
  }

private:
  std::vector<Point> points;
  std::vector<Point> covered;
};

#endif