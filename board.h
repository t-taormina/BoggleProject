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
static string const CUBE_ONE = "AAEEGN";
static string const CUBE_TWO = "ABBJOO";
static string const CUBE_THREE = "ACHOPS";
static string const CUBE_FOUR = "AFFKPS";
static string const CUBE_FIVE = "AOOTTW";
static string const CUBE_SIX = "CIMOTU";
static string const CUBE_SEVEN = "DEILRX";
static string const CUBE_EIGHT = "DELRVY";
static string const CUBE_NINE = "DISTTY";
static string const CUBE_TEN = "EEGHNW";
static string const CUBE_ELEVEN = "EEINSU";
static string const CUBE_TWELVE = "EHRTVW";
static string const CUBE_THIRTEEN = "EIOSST";
static string const CUBE_FOURTEEN = "ELRTTY";
static string const CUBE_FIFTEEN = "HIMNQU";
static string const CUBE_SIXTEEN = "HLNNRZ";
static string const MYFILE = "practice.txt";
      
 
class Board : public Dictionary{
    public:
        string result;
        Dictionary dict;

        char boardArray[4][4];
        std::array<string, 16> CUBE_ARRAY = {CUBE_ONE, CUBE_TWO, CUBE_THREE, 
                CUBE_FOUR, CUBE_FIVE, CUBE_SIX, CUBE_SEVEN, CUBE_EIGHT,
                CUBE_NINE, CUBE_TEN, CUBE_ELEVEN, CUBE_TWELVE, CUBE_THIRTEEN,
                CUBE_FOURTEEN, CUBE_FIFTEEN, CUBE_SIXTEEN};
 
        Board();
        Board(string& myfile, string _userInput);

        bool inBounds(int row,int col);
        void fillBoard();
        void displayBoard();  
        string getRandomLetters();
        int getRandom();

};

#endif 
