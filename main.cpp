#include <iostream> 
#include <cctype> 
#include <random>  
#include <string>

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

string CUBE_ARRAY[] = {CUBE_ONE, CUBE_TWO, CUBE_THREE, CUBE_FOUR, CUBE_FIVE, 
  CUBE_SIX, CUBE_SEVEN, CUBE_EIGHT, CUBE_NINE, CUBE_TEN, CUBE_ELEVEN, 
  CUBE_TWELVE, CUBE_THIRTEEN, CUBE_FOURTEEN, CUBE_FIFTEEN, CUBE_SIXTEEN};

string getRandomLetters();
int getRandom();
int main( void )
{
  string result = getRandomLetters();
}

int getRandom() {
  std::random_device os_seed;
  const u32 seed = os_seed();
	int num;

  engine generator( seed );
  std::uniform_int_distribution< u32 > distribute( 0, 6 );
  num = distribute(generator);

  return num;
}

string getRandomLetters() {
  string result;

  for (int i = 0; i < NUM_CUBES; i++){
    result.push_back(CUBE_ARRAY[i][getRandom()]);
  }
  std::cout << result << std::endl;
  return result;
}

void displayBoard() {

}
  
