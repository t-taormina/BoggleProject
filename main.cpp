//Boggle Project CST136
//

#include "board.h"
  
int main( void ) {
  string myfile = "Dictionary.txt";
  Board board1(myfile, "");
  board1.displayBoard();
  board1.SolveBoard();
  board1.printArray();
  int x = board1.getComputerScore();
  cout << x << endl;
  return 0;
}

