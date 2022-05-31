//Boggle Project CST136
//tyler.taormina@oit.edu
//freddy.hernandezjimenez@oit.edu
//rayyan.ansari@oit.edu

#include "board.h"

#include <iostream>
using std::endl;
using std::cout;
string myFile = "Dictionary.txt";

typedef bool(*FunctionPointer)();
bool testBoardSolve();
bool testConstructionAndDisplay();
FunctionPointer testFunctions[] = {testConstructionAndDisplay, testBoardSolve};

int main()
{
    bool testsPassed = true;
    int testCount = 1;
    Board b1;

    for(FunctionPointer func : testFunctions) {
        if(func())
            cout << "passing test " << testCount << "..." << endl;

        else {
            cout << "TEST " << testCount << " FAILED!" << endl;
            testsPassed = false;
        }
        testCount++;
    }

    if(testsPassed) {
        cout << "All Tests Passing..." << endl;
        cout << "Nice work!" << endl;
    }
    else
        cout << "FAIL!" << endl;

    return 0;
}

//The way we set up the board class makes it so that when we initialize the board with
// the default parameter, it will automaticlly open the lexicon text file and then 
// load the text file into the dictionary data structure. This means that by testing 
// the board class, we are confirming that we successfully implemented the dictionary
// class and that our data structure is working as intended. Another note to make is 
// that when we use the default parameter, we get a random board layout. This makes 
// certain things difficult to test. We will test what we can below, mainly using the 
// parameterized constructor since that is something we assuredly test. 
bool testConstructionAndDisplay() {
  cout << "************************************************************************" << endl;
  cout << "Testing Board displays..." << endl;
  cout << "************************************************************************" << endl;
  bool success = true;
  Board b(myFile, "lookhereforebord");
  cout << b << endl;
  cout << "\n\n" << endl;
  cout << "The next two boards will be random.Visually confirm that they are different..." << endl;
  cout << "\n\n" << endl;
  cout << "The first board will display the error message for an incorrect number of letters " << endl;
  cout << "used in manual creation of a board." << endl;

  cout << "\n\n" << endl;
  Board b1(myFile, "chec the half b");
  cout << b1 << endl;
  cout << "\n" << endl;

  Board b2;
  cout << b2 << endl;
  return success;
}

//For this test, again we will have to make a test that simplifies the board solver due 
//to the challenge of creating a board that has predetermined solutions. We chose
// to create boards that have one solution or no solutions to check and see if our program 
// properly solves the boggle board. Another function that we will lightly test hear
// is the scoring function.
bool testBoardSolve() {
  cout << "************************************************************************" << endl;
  cout << "Testing Board displays..." << endl;
  cout << "************************************************************************" << endl;
  bool success = true;

  Board b(myFile, "xxxhxxaxxppxyxxx");
  cout << b << endl;
  b.solveBoard();
  b.printArrays();
  cout << "Computer score: " << b.getComputerScore() << endl;
  bool check = (b.computerList[0] == "happy");
  if (!check) { success = false; }

  Board b2(myFile, "xxxhxxaxxxpxyxxx");
  cout << b2 << endl;
  b2.solveBoard();
  b2.printArrays();
  cout << "Computer score: " << b2.getComputerScore() << endl;
  check = (b2.computerList.size() == 0);
  if (!check) { success = false; }
  return success;
}
 
