#include <stdio.h>
#include "Point.h"
#include "Board.h"
#include "Piece.h"

bool tryToPlace(PuzzlePiece *piece, Board *board) {
  for (Point p : board->getFree()) {
    std::cout << "Trying to place " << piece->getName() << " piece at " << p.getX() << ", " << p.getY() << std::endl;    

    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 4; j++) {
        piece->setAnchor(p);
        if (board->canPlacePiece(piece, p)) {
          std::cout << "Placing piece " << piece->getName() << " at " << p.getX() << ", " << p.getY() << "\n" << std::endl;
          board->placePiece(piece, p);
          board->printPoints();
          // board->printCovered();
          return true;
        } 
        // else {
        //   // print the point that is not valid
        //   for (Point b : piece->body(p)) {
        //     if (!board->isValidPoint(b)) {
        //       std::cout << "Point " << b.getX() << ", " << b.getY() << " is not valid" << std::endl;
        //     } 
        //     else if (board->pointInVec(b, board->getCovered())) {
        //       std::cout << "Point " << b.getX() << ", " << b.getY() << " is already covered" << std::endl;
        //     }
        //   }
        // }
        // std::cout << "Rotating " << piece->getName() << " piece ";
        piece->rotate();
        // piece->printOneLine();
      }
      // std::cout << "Mirroring " << piece->getName() << " piece" << std::endl;
      piece->mirror();
    }
  }
  return false;
}

int main() {
  Board board;
  board.printPoints();

  std::vector<PuzzlePiece> allPieces = { OPiece(), LPiece(), TPiece(), SPiece(), ZPiece(), UPiece(), PPiece(), JPiece() };
  
  for (PuzzlePiece piece : allPieces)
    tryToPlace(&piece, &board);

  return 0;
}