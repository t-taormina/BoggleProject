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

  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 4; j++){
      std::cout << board1.board[i][j] << std::endl;
    }
  }

    
  return 0;
}


