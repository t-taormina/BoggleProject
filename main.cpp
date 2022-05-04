//Boggle Project CST136
//

#include "board.h"
  
int main( void ) {
  Board board4;
  board4.displayBoard();
  std::cout << std::endl;

  Board board("Isten");
  board.displayBoard();
  std::cout << std::endl;
    
  Board board1("CantReadThisMann");
  board1.displayBoard();


    
  return 0;
}


