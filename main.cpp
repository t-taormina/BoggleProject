//Boggle Project CST136
//

#include "board.h"
  
int main( void ) {
  Board board4;
  board4.displayBoard();
  Board board("Isten");
  board.displayBoard();
  Board board1("CantReadThisMann");
  board1.displayBoard();
  return 0;
}


