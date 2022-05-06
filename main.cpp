//Boggle Project CST136
//

#include "board.h"
  
int main( void ) {
  string myfile = "Dictionary.txt";
  Board board1(myfile, "CANTREADTHISMANN");
  cout << board1.dict.wordCount() << endl;
  board1.displayBoard();
    
  return 0;
}

