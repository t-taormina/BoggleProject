#include "board.h"

Board::Board(){
    result = getRandomLetters();
}

Board::Board(string _userInput){
    if(_userInput.length() == 16){
        result = _userInput;
    }
    else{
        result = "MustBe16LetrDude";
    }
}

int Board::getRandom() {
    std::random_device os_seed;
    const u32 seed = os_seed();
    engine generator( seed );
    std::uniform_int_distribution< u32 > distribute( 0,5 );
    int num = distribute(generator);
    return num;
} 

string Board::getRandomLetters() {
    string _result = "";
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(CUBE_ARRAY.begin(), CUBE_ARRAY.end(), std::default_random_engine(seed));
    for (int i = 0; i < NUM_CUBES + 1; i++){
        _result.push_back(CUBE_ARRAY[i][getRandom()]);
    }
    return _result;
}

void Board::displayBoard() {
    int counter = 0;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            std::cout << " " << result[counter] << " ";
            counter++;  
        }
        std::cout <<  std::endl;
    }
}
