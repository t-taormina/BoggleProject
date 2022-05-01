//Boggle Project CST136
//

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

std::array<string,16> CUBE_ARRAY = {CUBE_ONE, CUBE_TWO, CUBE_THREE, CUBE_FOUR, CUBE_FIVE, 
  CUBE_SIX, CUBE_SEVEN, CUBE_EIGHT, CUBE_NINE, CUBE_TEN, CUBE_ELEVEN, 
  CUBE_TWELVE, CUBE_THIRTEEN, CUBE_FOURTEEN, CUBE_FIFTEEN, CUBE_SIXTEEN};

void displayBoard(string _result);  
string getRandomLetters();
int getRandom();

int main( void ) {
  string result = getRandomLetters();
  displayBoard(result);
  return 0;
}

int getRandom() {
  std::random_device os_seed;
  const u32 seed = os_seed();
  engine generator( seed );
  std::uniform_int_distribution< u32 > distribute( 0,5 );
  int num = distribute(generator);

  return num;
} 

string getRandomLetters() {
  string result = "";
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  shuffle(CUBE_ARRAY.begin(), CUBE_ARRAY.end(), std::default_random_engine(seed));
  for (int i = 0; i < NUM_CUBES + 1; i++){
    std::cout << CUBE_ARRAY[i] << std::endl;
    result.push_back(CUBE_ARRAY[i][getRandom()]);
  }
  return result;

}

void displayBoard(string _result) {
  int counter = 0;
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 4; j++){
      std::cout << " " << _result[counter] << " ";
      counter++;  
    }
    std::cout <<  std::endl;
  }
}



