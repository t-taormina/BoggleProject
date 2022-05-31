//Boggle Project CST136
//tyler.taormina@oit.edu
//freddy.hernandezjimenez@oit.edu
//rayyan.ansari@oit.edu

#include "board.h"
  
void displayMenu(int&);
void processChoice(bool&, int);
void clearBuffer(); 
void userPlay(Board& _board);
void compareScores(Board& _board);
void regularPlay();
void inputPlay();
string grabInput();
void displayWelcome();

int main( void ) {
  int menu_choice;
  bool flag = true;

  displayWelcome();
  cout << "Press enter to continue..." << endl;
  while ( getchar() != '\n');
  
  while(flag)
    {
        displayMenu(menu_choice);
        processChoice(flag, menu_choice);
    }

  return 0;
}


void displayMenu(int& menu_choice) 
{
     //Displays the menu of functions for the user to choose from.
    menu_choice = 0;
    cout << "==================================================================\n";
    cout << "                         MENU" << endl;
    cout << "==================================================================\n";

    cout << "1) Play Boggle.\n";
    cout << "2) Establish your own board and play boggle.\n";
    cout << "3) Exit.\n";
    cout << "Enter: ";
    cin >> menu_choice;
    if (menu_choice > 3 || menu_choice < 1) 
    {
        cout << "Invalid Entry. Please enter a number from the options list provided.\n\n\n\n" << endl;
        displayMenu(menu_choice);
    }
}

  
void processChoice (bool& flag, int menu_choice)
{
    //Takes in user input for menu choice and calls the appropriate function.
    string temp;
    int check = 1;
    clearBuffer();
    switch(menu_choice)
    {
        case 1:
          regularPlay();
          break;

        case 2: 
          inputPlay();
          break;

        case 3:
          cout << "Are you sure you want to exit?" << endl;
          check = 0;
          break;

        default:
            break;
    }

    if (check == 0)
    {
        cout << "Enter 0 to end program.\n" << endl;
        cout << "Enter any other number to continue program.\n" << endl;
        cin >> flag;
    }
}

//Clears buffer after menu choice so as not to interfere with the following user inputs.
void clearBuffer() {
	char c;
	do {
		c = getchar();
	} while (c != '\n' && c != EOF);
}

string grabInput() {
  string _input;
  cout << "Enter a word: ";
  cin >> _input;
  clearBuffer();
  return _input;
}

void userPlay(Board& _board) {
  bool flag = true;
  string _input;
  string _continue;

  while(flag) {
    _input = grabInput();
    transform(_input.begin(), _input.end(), _input.begin(), ::tolower);
    bool check = _board.humanWordSearch(_input);
    if(check) {
      _board.humanList.push_back(_input);
      cout << "VALID WORD!" << endl;
    }
    else { cout << "INVALID WORD!" << endl; }
    cout << "Enter 0 to stop. Any other number to continue: ";
    cin >> _continue;
    if (_continue == "0") { flag = false; }
  }
  cout << "\n\nNice playing! Tallying scores..." << endl;
  clearBuffer();
  cout << "Press enter to continue..." << endl;
  while ( getchar() != '\n');
}

void regularPlay() {
  cout << "Lets play!" << endl;
  string myfile = "Dictionary.txt";
  Board _board;
  _board.displayBoard();
  _board.computerWordSearch();
  userPlay(_board);
  compareScores(_board);
   _board.printArrays();
}

void inputPlay() {
  string _input;
  cout << "Enter the characters that you would like to use in a single entry." << endl;
  cout << "You will be entering characters from left to right and from top to bottom. " << endl;
  cout << "This means that the first character will be the top left and the last character will " << endl;
  cout << "be the bottom right." << endl;
  cout << "Remember, you must enter 16 characters or we will give you a random board!" << endl;
  cout << "Enter the characters of your choice: " << endl; 
  cin >> _input;
  string myfile = "Dictionary.txt";
  Board _board(myfile, _input);
  _board.displayBoard();
  _board.computerWordSearch();
  userPlay(_board);
  compareScores(_board);
   _board.printArrays();
}

void compareScores(Board& _board) {
  int h_score, c_score;
  h_score = _board.getScoreHuman();
  c_score = _board.getScoreComputer();
  if (c_score > h_score) {
    cout << "GOOD TRY. THANKS FOR PLAYING!" << endl;
    
  } else if (c_score == h_score) {
    cout << "IT'S A DRAW! WELL DONE. THANKS FOR PLAYING!" << endl;

  } else {
    cout << "WINNER!! YOU SPENT SOME TIME HERE. THANKS FOR PLAYING!" << endl;
  }

  cout << "Human score: " << h_score << endl;
  cout << "Computer score: " << c_score << endl;
  cout << "Press enter to continue..." << endl;
  while ( getchar() != '\n');
}

void displayWelcome() {
  cout << " ____________" << endl;
  cout << "|  ________  |" << endl;
  cout << "| | Boggle!| |" << endl;
  cout << "| |________| |" << endl;
  cout << "|____________|" << endl;
  cout << "\n\n";
  cout << "Welcome to boggle!" << endl;
}
