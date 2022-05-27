#include "dictionary.h"

Dictionary::Dictionary()
{
    root = new Node;
    root->flag = false;
    numWords = 0;
}

Dictionary::~Dictionary(){}

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
    //cout << "Counter" << endl;
    //cout << counter << endl;
}

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

int Dictionary::wordCount()
{
    return numWords;
}

