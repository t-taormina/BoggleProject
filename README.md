# BoggleProject

## Contacts
- tyler.taormina@oit.edu
- freddy.hernandezjimenez@oit.edu
- rayyan.ansari@oit.edu


## How to run this program
- When running from terminal, make sure you are in the project directory. 

- If using GNU compiler, run the command..
	```
 	g++ -std=c++11 main.cpp board.cpp dictionary.cpp -o main
	```
- then run the command... 
	``` 
	./main
	```
- If you want to run the test suite, run the command...
```
 	g++ -std=c++11 test.cpp board.cpp dictionary.cpp -o test 
```
- then run the command... 
	``` 
	./test
	```

- Program should output to the terminal.
- There are other ways to compile and run the program depending on your OS and setup. This is just one way.


## Overveiw
Boggle is a game played on a square grid onto which you randomly distribute a set of letter cubes. Letter cubes 
are 6-sided dice with a letter on each side rather than a number. The goal is to find words on the board by tracing 
a path through neighboring letters. Two letters are neighbors if they are next to each other horizontally, vertically, 
or diagonally. There are up to eight letters near a cube. Each cube can be used at most once in a word. In the 
real-life version of this game, all players work at the same time, listing the words they find on a piece of paper. 
When  time  is  called,  duplicates  are  removed  from  the  lists  and  the  players  receive  one  point  for  each  unique 
word, that is, for each word that player found that no other player was able to find. 

## Good links for different functions 
- https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c
- https://www.cplusplus.com/reference/algorithm/shuffle/
- https://jarv.is/notes/how-to-pull-request-fork-github/
- 	
	
