#ifndef DICE_H
#define DICE_H
#include <string>
#include <array>
using std::string;

struct Dice {
        int NUM_CUBES = 16;
        string CUBE_ONE = "AAEEGN";
        string CUBE_TWO = "ABBJOO";
        string CUBE_THREE = "ACHOPS";
        string CUBE_FOUR = "AFFKPS";
        string CUBE_FIVE = "AOOTTW";
        string CUBE_SIX = "CIMOTU";
        string CUBE_SEVEN = "DEILRX";
        string CUBE_EIGHT = "DELRVY";
        string CUBE_NINE = "DISTTY";
        string CUBE_TEN = "EEGHNW";
        string CUBE_ELEVEN = "EEINSU";
        string CUBE_TWELVE = "EHRTVW";
        string CUBE_THIRTEEN = "EIOSST";
        string CUBE_FOURTEEN = "ELRTTY";
        string CUBE_FIFTEEN = "HIMNQU";
        string CUBE_SIXTEEN = "HLNNRZ";
        std::array<string,16>  CUBE_ARRAY = {CUBE_ONE, CUBE_TWO, CUBE_THREE, 
                CUBE_FOUR, CUBE_FIVE, CUBE_SIX, CUBE_SEVEN, CUBE_EIGHT,
                CUBE_NINE, CUBE_TEN, CUBE_ELEVEN, CUBE_TWELVE, CUBE_THIRTEEN,
                CUBE_FOURTEEN, CUBE_FIFTEEN, CUBE_SIXTEEN};
};

#endif 
