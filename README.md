# BoggleProject

Game Overview
Boggle is a game played on a square grid onto which you randomly distribute a set of letter cubes. Letter cubes 
are 6-sided dice with a letter on each side rather than a number. The goal is to find words on the board by tracing 
a path through neighboring letters. Two letters are neighbors if they are next to each other horizontally, vertically, 
or diagonally. There are up to eight letters near a cube. Each cube can be used at most once in a word. In the 
real-life version of this game, all players work at the same time, listing the words they find on a piece of paper. 
When  time  is  called,  duplicates  are  removed  from  the  lists  and  the  players  receive  one  point  for  each  unique 
word, that is, for each word that player found that no other player was able to find.
Your team will write a program that plays this game, adapted for one human to play against a computer opponent. 
Unfortunately, the computer knows recursive backtracking, so it can find every word on the board and destroy 
you every time. But it's still fun to write a program that can so soundly thrash you again and again.
To begin a game, you shake up the letter cubes and lay them out on the board. The human player plays first, 
entering words one by one. Your code first verifies that the word is valid, then you add it to the player's word 
list and award the player points according to the word's length (one point per letter ≥ 4). A word is valid if it 
meets all of the following conditions:
1. at least 4 letters long
2. is a word found in the English lexicon
3. can be formed by connecting neighboring letter cubes (using any given cube only once)
4. has not already been formed by the player in this game (even if there are multiple paths on the board to 
form the same word, the word is counted at most once)
Do you want to generate a random board? y
It's your turn!
FYCL
IOMG
ORIL
HJHU
...
Your words (5): {"FOIL", "FORM", "ROOF", "ROOM", "ROOMY"}
Your score: 6
Type a word (or Enter to stop):
It's my turn!
My words (16): {"COIF", "COIL", "COIR", "CORM", "FIRM", "GIRO", "GLIM", "HOOF", "IGLU", "LIMO", "LIMY", 
"MIRI", "MOIL", "MOOR", "RIMY", "ROIL"}
My score: 16
Sorry, I win.
Oregon Institute of Technology
CST 136 OOP with C++
Project #1: Boogle Game
2
Setting up the Game Board
The real Boggle game comes with sixteen letter cubes, each with particular letters on each of their six faces. The 
letters on each cube are not random; they were chosen in such a way that common letters come up more often 
and  it  is  easier  to  get  a  good  mix  of  vowels  and  consonants.  We  want  your  Boggle  game  to  match  this.  The 
following table lists all of the letters on all six faces of each of the sixteen cubes from the original Boggle. You 
should decide on an appropriate way to represent this information in your program and declare it accordingly.
AAEEGN ABBJOO ACHOPS AFFKPS
AOOTTW CIMOTU DEILRX DELRVY
DISTTY EEGHNW EEINSU EHRTVW
EIOSST ELRTTY HIMNQU HLNNRZ
At the beginning of each game, "shake" the board cubes. There are two different random aspects to consider:
5. A random location on the 4x4 game board should be chosen for each cube. (For example, the AAEEGN 
cube should not always appear in the top-left square of the board; it should randomly appear in one of 
the 16 available squares with equal probability.)
6. A random side from each cube should be chosen to be the face-up letter of that cube. (For example, the 
AAEEGN cube should not always show A; it should randomly show A 1/3 of the time, E 1/3 of the time, 
G 1/6 of the time, and N 1/6 of the time.)
Your game must also have an option where the user can enter a manual board configuration. In this option, rather 
than randomly choosing the letters to be on the board, the user enters a string of 16 characters, representing the 
cubes from left to right, top to bottom. (This is also a useful feature for testing your code.) Verify that the user's 
string is long enough to fill the board and re-prompt if it is not exactly 16 characters in length. Re-prompt the 
user if any of the 16 characters is not a letter from A-Z. Your code should work case-insensitively. You needn’t 
check whether the 16 letters typed could actually be formed from the 16 letter cubes; just accept any 16 alphabetic 
letters.
Oregon Institute of Technology
CST 136 OOP with C++
Project #1: Boogle Game
3
Human Player's Turn
The  human  player  enters  each  word  she  finds  on  the  board.  As  described  previously,  for  each  word  the  user 
types, you must check that it is at least four letters long, contained in the English lexicon, has not already been 
included in the player's word list, and can be formed on the board from neighboring cubes. If any condition fails, 
alert  the  user.  There  is  no  penalty  for  trying  an  invalid  word,  but  invalid  words  also  do  not  count  toward  the 
player's list or score.
If the word is valid, you add the word to the player's word list and score. The length of the word determines the 
score, with each letter ≥ 4 being worth 1 point. For example, a 4-letter word is worth 1 point; a 5-letter word is 
worth 2 points; 6-letter words are worth 3; 7-letter words are worth 4; and so on. The player enters a blank line 
when done finding words, which signals the end of the human's turn.
Computer's Turn
Once the human player is done entering words, the computer then searches the entire board to find the remaining 
words missed by the human player. The computer earns points for each remaining word found that meets the 
requirements (minimum length, contained in English lexicon, not already found, and can be formed on board). 
If the computer's resulting score is strictly greater than the human's, the computer wins. If the players tie or if 
the human's score exceeds the computer's, the human player wins.
You can find all words on the board using recursive backtracking. The idea is to start from a given letter cube, 
then explore neighboring cubes around it and try all partial strings that can be made, then try each neighbor's 
neighbor, and so on. The algorithm is roughly the following:
for each letter cube c:
  mark cube c as visited. // choose
  for each neighboring cube next to c:
    explore all words that could start with c's letter. // explore
  un-mark cube c as visited. // un-choose
Oregon Institute of Technology
CST 136 OOP with C++
Project #1: Boogle Game
4
Boggle.cpp / h
Most of your code should be in the Boggle.h and Boggle.cpp files, which should contain the implementation of 
a Boggle class. A Boggle object represents the current board and state for a single Boggle game, and it should 
have methods to perform most major game functions like finding words on the board and keeping score. Declare 
all Boggle class members in Boggle.h and implement their bodies in Boggle.cpp. 
Below  are  some  required  members  below  that  your  class  MUST  have.  You  also  MUST  include  canonical 
constructors and a destructor (a total of 5 methods).
Do not change the headings of any of the following methods. Do not add parameters; do not rename them. You 
MUST implement these methods exactly with these exact headings. (See note below about const.)
One partner MUST do b.humanWordSearch, the other partner MUST do b.computerWordSearch. It may be that 
each of these methods call a “helper” method. However, recursion should be done in each of these methods and 
each method should be done by different partners.
Boggle Method Description
Boggle(fstream lexicon, string 
boardText) This constructor initializes the Boggle board to use the given 
dictionary lexicon to look up words and use the given 16-letter string 
to initialize the 16 board cubes from top-left to bottom-right. If the 
string is empty, generate a random shuffled board. This method is 
case-insensitive; it accepts the board text whether it is passed in 
upper, lower, or mixed case.
This constructor is considered the parameterized constructor.
char b.getLetter(int row, int col) This method returns the character that is stored in the Boggle board at 
the given 0-based row and column. If the row and/or column are out 
of bounds, throw an exception.
bool b.checkWord(string word) This method checks whether the given word string is suitable to 
search for: that is, whether it is in the dictionary, long enough to be a 
valid Boggle word, and has not already been found. It returns a 
Boolean result of true if the word is suitable, false otherwise. This 
method is case-insensitive; it verifies the word whether it is passed in 
upper, lower, or mixed case.
bool b.humanWordSearch(string 
word) This method performs a search on the board for an individual word. If 
the word can be formed, it is added to the human's set of found 
words. The method returns a Boolean result of whether the word can 
be formed. This method uses recursive backtracking. If the word is 
unsuitable, no recursive search is performed. This method is case-
insensitive; searches for the word whether it is passed in upper, lower, 
or mixed case.
string* b.computerWordSearch() This method performs a search on the board for all words that can be 
formed (that have not already been found by the human player) and 
returns them as an array of strings. This method uses recursive 
backtracking. Though like the human search, it is different because it 
Oregon Institute of Technology
CST 136 OOP with C++
Project #1: Boogle Game
5
looks for ALL words; therefore, its code should be implemented 
separately from humanWordSearch. The words in this set should be 
all uppercase.
This is the search that you will time chrono.
int b.getScoreHuman() This method returns the total number of points the human player has 
scored in the game so far as an integer. This total is 0 when the game 
begins, but whenever a successful human word search is performed, 
points for that word are added to the human's total score.
int b.getScoreComputer() This method returns the total number of points the computer player 
has scored in the game as an integer. This total is initially 0 when the 
game begins, but after a computer word search is performed, all 
points for those words are added to the computer's total score.
ostream& operator<< (ostream& 
stream) This method prints a Boggle object to the console. The operator 
should print only the 4x4 grid of characters representing the board as 
four lines of text. It should print the board text in all uppercase.
Once  again  for  emphasis,  do  not  modify  the  names,  parameters,  or  return  types  of  the  preceding  methods. 
Implement them as-is. The one exception is that you can (and should) modify headers to make the method const 
if it does not modify the state of your Boggle object. Review all of your methods (the ones provided above, and 
any others you choose to add to your class) and make them const as much as possible.
Case sensitivity: Your methods that accept strings must be case-insensitive; they should work with upper, lower, 
or mixed case. This should be enforced in your program by the Boggle class, not by the boggleplay.cpp code.
Adding your own methods: for this project, it is up to your team to come up with some of the members. The 
Boggle class members listed represent a large fraction of that class's behavior. But your team can, and should, 
add other members to implement all of the appropriate behavior for this assignment. Your added members should 
be  public  if  they  are  to  be  called  directly  by  the  boggleplay.cpp  code,  and  private  otherwise.  You  must  also 
decide what code and/or data should go in boggleplay.cpp, and what should go in the Boggle class. Part of the 
challenge of this assignment is learning how to design a class effectively. Remember that each method of your 
class should have a single clear, coherent purpose.
Oregon Institute of Technology
CST 136 OOP with C++
Project #1: Boogle Game
6
Here are some suggestions for good methods to put in your Boggle class:
 Though  the  boggleplay.cpp  file  should  do  all  console  I/O,  your  Boggle  class  should  have  lots  of 
convenient methods for boggleplay to call so that it doesn't need as much complex logic. No recursion 
or  backtracking  should  take  place  in  boggleplay;  all  such  recursive  searching  should  happen  in  the 
Boggle class.
 The boggleplay code needs to be able to display various aspects of the game state, such as all words that 
have been found by each player, along with the players' scores. The Boggle class should keep track of 
such things, NOT boggleplay. The boggleplay code should ask the Boggle class for this information by 
calling accessor methods on it, which should return appropriate data to the caller. Note that the Boggle 
class itself should not contain any output statements to cout; let boggleplay do that.
 Make a method and/or parameter const if it does not perform modification of the object's state.
 Make a method private if it is used internally and not to be called by the client (a "helper").
 Do not add methods to your Boggle class that directly return internal data structures in a way that allows 
the  client  to  make  direct  modifications  to  them.  (This  is  called  "representation  exposure"  and  is 
considered poor style.)
Member variables: The private member variables that should go inside the Boggle class have not been defined; 
your team must decide those yourself. Here are some thoughts about data members that your class might need:
 Your team will certainly need a data structure to represent the current game board state, meaning the 16 
letter cubes and what letter is showing on top of each cube. The exact choice of data structure is up to 
you, but you should make an efficient and appropriate choice.
 It is fine to declare additional data structures, such as a collection of words found, etc.
 All data member variables inside a Boggle object should be private.
Searching:  You  don't  want  to  visit  the  same  letter  cube  twice  during  a  given  exploration,  so  for  the  search 
algorithm to work, your Boggle class needs some way to "mark" whether a letter cube has been visited or not. 
You could use a separate structure for marking, or modify your existing board, etc. It's up to your team, as long 
as it works.
Time your search method using chrono. Use several different words of different lengths to time the searching.
