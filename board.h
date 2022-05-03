#ifndef BOARD_H
#define BOARD_H
#include "dice.h"
#include <iostream> 
#include <chrono>
#include <cctype> 
#include <random>  
#include <string>
#include <algorithm>
#include <array>

using std::string;  
using u32 = uint_least32_t; 
using engine = std::mt19937;

class Board : public Dice {
    public:
        string result;
        char board[4][4];

        Board();
        Board(string);

        void fillBoard();
        void displayBoard();  
        string getRandomLetters();
        int getRandom();
};

#endif 
