#ifndef BOARD_H
#define BOARD_H
#include <iostream> 
#include <fstream>  
#include <chrono>
#include <cctype> 
#include <random>  
#include <string>
#include <algorithm>
#include <array>
#include "dictionary.h"

using std::string;  
using u32 = uint_least32_t; 
using engine = std::mt19937;
    
static int const NUM_CUBES = 16;
static string const CUBE_ONE = "aaeegn";
static string const CUBE_TWO = "abbjoo";
static string const CUBE_THREE = "achops";
static string const CUBE_FOUR = "affkps";
static string const CUBE_FIVE = "aoottw";
static string const CUBE_SIX = "cimotu";
static string const CUBE_SEVEN = "deilrx";
static string const CUBE_EIGHT = "delrvy";
static string const CUBE_NINE = "distty";
static string const CUBE_TEN = "eeghnw";
static string const CUBE_ELEVEN = "eeinsu";
static string const CUBE_TWELVE = "ehrtvw";
static string const CUBE_THIRTEEN = "eiosst";
static string const CUBE_FOURTEEN = "elrtty";
static string const CUBE_FIFTEEN = "himnqu";
static string const CUBE_SIXTEEN = "hlnnrz";
      
 
class Board {
    public:
        string result;
        int humanScore;
        int computerScore;
        Dictionary dict;
        Dictionary wordsFound;
        vector<string> computerList;
        vector<string> humanList;

        char boardArray[4][4];
        bool checkedArray[4][4] = {{false, false, false, false}, {false, false, false, false}, {false, false, false, false}, {false, false, false, false}};
        std::array<string, 16> CUBE_ARRAY = {CUBE_ONE, CUBE_TWO, CUBE_THREE, 
                CUBE_FOUR, CUBE_FIVE, CUBE_SIX, CUBE_SEVEN, CUBE_EIGHT,
                CUBE_NINE, CUBE_TEN, CUBE_ELEVEN, CUBE_TWELVE, CUBE_THIRTEEN,
                CUBE_FOURTEEN, CUBE_FIFTEEN, CUBE_SIXTEEN};
 
        Board();
        Board(string& myfile, string _userInput);
        ~Board();

        void fillBoard();
        void displayBoard();  
        bool inBounds(int row,int col);
        string getRandomLetters();
        int getRandomIndex();

        int getHumanScore();
        void humanPlayersTurn();

        int getComputerScore();
        void solveBoard();
        void searchForWord(int row, int col, string currPrefix);

        int score(int word_length);
        int score();
        void printComputerArray();
        void printHumanArray();
};

#endif 
