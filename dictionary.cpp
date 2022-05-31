#include "dictionary.h"

Dictionary::Dictionary()
{
    root = new Node;
    root->flag = false;
    numWords = 0;
}

Dictionary::~Dictionary(){}

//Inputs words from the lexicon to the dictionary.
void Dictionary::addWord(string word)
{
    currNode = root;
    
    for(int i = 0; i < word.length(); i++) {
        
        int index = (int)word[i] - (int)'a';
        
        if(currNode->arr[index] == NULL) {
            currNode->arr[index] = new Node;
            counter++;
            (currNode->arr[index])->flag = false;
        }
        
        currNode = currNode->arr[index];
    }
    
    currNode->flag = true;
    numWords++;
    currNode = NULL;
}

void Dictionary::deleteNodes(Node* node) {
    for(int i = 0; i < MAX; i++) {
        if (node->arr[i] != NULL) {
            deleteNodes(node->arr[i]);
            delete node->arr[i];
            counter--;
        } 
    }
}

//Checks to see if a given string from the board is a word in the lexicon.
bool Dictionary::isWord(string word)
{
    currNode = root;
    bool isWord = false;
    
    for(int i = 0; i < word.length(); i++) {
        
        int index = (int)word[i] - (int)'a';
  
        if(currNode->arr[index] == NULL)
            return false;
        
        isWord = currNode->arr[index]->flag;
        currNode = currNode->arr[index];
        
    }
    
    currNode = NULL;
    return isWord;
}

//Checks words as they are put together from the board. If a prefix doesn't match 
// any words in the dictionary, that prefix is abandoned and the next search is 
// begun.
bool Dictionary::isPrefix(string word)
{
    currNode = root;
    
    for(int i = 0; i < word.length(); i++) {
        
        int index = (int)word[i] - (int)'a';
        
        if(currNode->arr[index] == NULL)
            return false;
        
        currNode = currNode->arr[index];
    }
    
    currNode = NULL;
    return true;
}

//Displays all words from the dictionary.
void Dictionary::PrintWords(string prefix)
{
    currNode = root;
    
    for(int i = 0; i < prefix.length(); i++) {
        
        int index = (int)prefix[i] - (int)'a';
        
        currNode = currNode->arr[index];
    }
    
    for(int i = 0; i < 26; i++) {
        
        char letter = (int)'a' + i;
        
        PrintHelper(currNode->arr[i], prefix+letter);
    }
    currNode = NULL;
}

void Dictionary::PrintHelper(Node* startNode, string prefix)
{
    if(startNode == NULL)
         
        return;
    
    if(startNode->flag)
        cout << prefix << endl;
    
    for(int i = 0; i < 26; i++) {
        
        char letter = (int)'a' + i;
        
        PrintHelper(startNode->arr[i], prefix+letter);
    }
}

//Total count of dictionary size.
int Dictionary::wordCount()
{
    return numWords;
}

