//Boggle Project CST136
//

#include "board.h"
  
void displayMenu(int&);
void processChoice(bool&, int);
void clearBuffer(); 
void regularPlay();
void inputPlay();
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

void clearBuffer() 
{
    // clears buffer after menu choice so as not to interfere with the following user inputs.
	char c;
	do {
		c = getchar();
	} while (c != '\n' && c != EOF);
}

void regularPlay() {
  cout << "Lets play!" << endl;
  string myfile = "Dictionary.txt";
  Board board1(myfile, "");
  board1.displayBoard();
  board1.solveBoard();
  int x = board1.getComputerScore();
  cout << "Computer score is: ";
  cout << x << endl;
}

void inputPlay() {
  cout << "input play" << endl;
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
