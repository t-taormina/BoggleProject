#include "board.h"

//Default constructor gives random board
Board::Board(){
    fillBoard();
}
//Parameterized constructor gives predetermined board.
//If an incorrect amount of charcters are given for the board 
// then the board will default to a random setup.
Board::Board(string& myfile, string _userInput){
    if(_userInput.length() == 16){
        result = _userInput;
        transform(result.begin(), result.end(), result.begin(), ::tolower);
        fillBoard();
    }
    else{
        result = getRandomLetters();
        fillBoard();
    }
    ifstream input(myfile);
    string word;
    
    if(!input) {
        cout << "Error reading file" << endl;
        return;
    }
    
    while(input >> word) {
       dict.addWord(word);
    }

    input.close();
}

Board::~Board() {
    dict.deleteNodes(dict.root);
    //dict.deleteNodes(dict.currNode);
    wordsFound.deleteNodes(wordsFound.root);
    //wordsFound.deleteNodes(wordsFound.currNode);
}

//Generates a random number for use by function 'getRandomLetters'.
//Used specifically to generate random index for cube array.
int Board::getRandom() {
    std::random_device os_seed;
    const uint_least32_t seed = os_seed();
    std::mt19937 generator( seed );
    std::uniform_int_distribution< uint_least32_t > distribute( 0,5 );
    int num = distribute(generator);
    return num;
} 

//Generates a random board by shuffling the 'CUBE' array and using a random index.
string Board::getRandomLetters() {
    string _result = "";
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(CUBE_ARRAY.begin(), CUBE_ARRAY.end(), std::default_random_engine(seed));
    for (int i = 0; i < NUM_CUBES + 1; i++){
        _result.push_back(CUBE_ARRAY[i][getRandom()]);
    }
    return _result;
}

//It... displays the board.
void Board::displayBoard() {
    string temp = result;
    transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
    int counter = 0;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            std::cout << " " << temp[counter] << " ";
            counter++;  
        }
        std::cout <<  std::endl;
    }
}

//Puts the string into an array for computer and human search. 
void Board::fillBoard(){
    int counter = 0;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            boardArray[i][j] = result[counter];
            counter++;  
        }
    }
}

void Board::SolveBoard() {
    string currPrefix;
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            SearchForWord(row, col, currPrefix);
        }
    }
}

void Board::SearchForWord(int row, int col, string currPrefix)
{
    if(row >= 4 || col >= 4)
        return;
    
    if(row < 0 || col < 0)
        return;
    
    if(checkedArray[row][col] != false)
        return;
    
    if(!dict.isPrefix(currPrefix))
        return;
    
    if(dict.isWord(currPrefix)) {
        if(!wordsFound.isWord(currPrefix)) {
            wordsFound.addWord(currPrefix);
            compList.push_back(currPrefix);
        }
    }
    
    currPrefix = currPrefix + boardArray[row][col];
    checkedArray[row][col] = true;
    
    SearchForWord(row , col - 1, currPrefix);
    SearchForWord(row , col + 1, currPrefix);
    SearchForWord(row - 1 , col, currPrefix);
    SearchForWord(row + 1 , col, currPrefix);
    SearchForWord(row + 1 , col + 1, currPrefix);
    SearchForWord(row + 1 , col - 1, currPrefix);
    SearchForWord(row - 1 , col + 1, currPrefix);
    SearchForWord(row - 1 , col - 1, currPrefix);

    checkedArray[row][col] = false;
}

void Board::printArray(){
    int total = compList.size();
    for (int i = 0; i < total; i++){
        cout << compList[i] << endl;
    }
}

int Board::getHumanScore() {
    humanScore = 0;
    for (int i = 0; i < humanList.size(); i++) {
        humanScore += score(humanList[i].length());
    }
    return humanScore;
}

int Board::getComputerScore() {
    computerScore = 0;
    for (int i = 0; i < compList.size(); i++) {
        computerScore += score(compList[i].length());
    }
    return computerScore;
}

int Board::score(int word_length){
    if (word_length < 4) { return 0;}
    else if (word_length == 4) { return 1;}
    else if (word_length == 5) { return 2;}
    else if (word_length == 6) { return 3;}
    else if (word_length == 7) { return 4;}
    else if (word_length == 8) { return 5;}
    else if (word_length == 9) { return 6;}
    else if (word_length == 10) { return 7;}
    else if (word_length == 11) { return 8;}
    else { return 9;}
}




