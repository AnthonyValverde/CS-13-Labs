#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
using namespace std;
// The puzzle will always have exactly 20 columns
const int numCols = 20;
int i;
int j;
string name;
int wordsFound;
bool searchPuzzleToTheRight(const char puzzle[][numCols], int numRows, const string &word, int rowStart, int colStart){
    
    for (i = 0; (i < word.size()) && (i+colStart < numCols -1); ++ i) {
        if (word.at(i) != puzzle[rowStart][colStart + i]) {
            return false;
        }
        else {
            return true;
    }
}
}
bool searchPuzzleToTheLeft(const char puzzle[][numCols], const string &word, int rowStart, int colStart, int numRows) {
    for (i = 0; (i < word.size()) && (colStart - i >= 0); ++ i) {
        if (word.at(i) != puzzle[rowStart][colStart - i]) {
            return false;
        }
        else {
            return true;
        }
    }
}
bool searchPuzzleToTheDown(const char puzzle[][numCols], const string &word, int rowStart, int colStart, int numRows) {
    for (i = 0; (i < word.size()) && (i + rowStart < numRows -1); ++ i) {
        if (word.at(i) != puzzle[rowStart+i][colStart]) {
            return false;
        }
        else {
            return true;
        }
    }
}
bool searchPuzzleToTheUp(const char puzzle[][numCols], const string &word, int rowStart, int colStart, int numRows) {
    for (i = 0; (i < word.size()) && (rowStart - i >=0); ++ i) {
        if (word.at(i) != puzzle[rowStart - i][colStart]) {
            return false;
        }
        else {
            return true;
        }
    }
}
bool searchPuzzleToTheTRD(const char puzzle[][numCols], const string &word, int rowStart, int colStart, int numRows) {
    for (i = 0; (i < word.size()) && (rowStart - i >= 0) && (colStart + i <numCols -1); ++ i) {
        if (word.at(i) != puzzle[rowStart - i][colStart + i]) {
            return false;
        }
        else {
            return true;
        }
    }
}
bool searchPuzzleToTheBRD(const char puzzle[][numCols], const string &word, int rowStart, int colStart, int numRows) {
    for (i = 0; (i < word.size()) && (rowStart +i < numRows -1) && (colStart + i < numCols-1); ++ i) {
        if (word.at(i) != puzzle[rowStart+ i][colStart + i]) {
            return false;
        }
        else {
            return true;
        }
    }
}
bool searchPuzzleToTheBLD(const char puzzle[][numCols], const string &word, int rowStart, int colStart, int numRows) {
    for (i = 0; (i < word.size()) && (rowStart + i < numRows-1) && (colStart -i >= 0); ++ i) {
        if (word.at(i) != puzzle[rowStart + i][colStart - i]) {
            return false;
        }
        else {
            return true;
        }
    }
}
bool searchPuzzleToTheTLD(const char puzzle[][numCols], const string &word, int rowStart, int colStart, int numRows) {
    for (i = 0; (i < word.size()) && (rowStart - i >= 0) && (colStart - i >= 0); ++ i) {
        if (word.at(i) != puzzle[rowStart - i][colStart - i]) {
            return false;
        }
        else {
            return true;
        }
    }
}
// TODO: implement searchPuzzle and any helper functions you want
void searchPuzzle(const char puzzle[][numCols], const string wordBank[], 
    vector <string> &discovered, int numRows, int numWords)
{
    int i;
    int j;
for (i = 0; i < numRows; ++i) {
    for (j = 0; j< numCols; ++j) {
        name = wordBank[numWords];
        if (puzzle[i][j] == name.at(0)) {
            searchPuzzleToTheRight;
            if(searchPuzzleToTheRight != false) {
                wordsFound = wordsFound + 1;
                discovered.at(wordsFound) = wordBank[wordsFound];
            }
            else if(searchPuzzleToTheRight == false ) {
            searchPuzzleToTheLeft;
            }
            if(searchPuzzleToTheLeft != false) {
                wordsFound = wordsFound + 1;
                discovered.at(wordsFound) = wordBank[wordsFound];
            }
            else if (searchPuzzleToTheLeft == false) {
            searchPuzzleToTheUp;
            }
            if(searchPuzzleToTheUp != false) {
                wordsFound = wordsFound + 1;
                discovered.at(wordsFound) = wordBank[wordsFound];
            }
             else if(searchPuzzleToTheUp == false ) {
            searchPuzzleToTheDown;
            }
            if(searchPuzzleToTheDown != false) {
                wordsFound = wordsFound + 1;
                discovered.at(wordsFound) = wordBank[wordsFound];
            }
            else if (searchPuzzleToTheDown == false) {
            searchPuzzleToTheTRD;
            }
              if(searchPuzzleToTheTRD != false) {
                wordsFound = wordsFound + 1;
                discovered.at(wordsFound) = wordBank[wordsFound];
            }
             else if(searchPuzzleToTheTRD == false ) {
            searchPuzzleToTheBRD;
            }
            if(searchPuzzleToTheBRD != false) {
                wordsFound = wordsFound + 1;
                discovered.at(wordsFound) = wordBank[wordsFound];
            }
            else if (searchPuzzleToTheBRD == false) {
            searchPuzzleToTheBLD;
            }
            if (searchPuzzleToTheBLD != false) {
                wordsFound = wordsFound + 1;
                discovered.at(wordsFound) = wordBank[wordsFound];
            }
            else if(searchPuzzleToTheBLD == false) {
            searchPuzzleToTheTLD;
            }
            if(searchPuzzleToTheTLD != false) {
                wordsFound = wordsFound + 1;
                discovered.at(wordsFound) = wordBank[wordsFound];
            }
            
        }
                
    
}
}
return;
}


// TODO: implement printVector
void printVector(const vector <string> &v)
{
    int numWords;
    for(i = 0; i < numWords; ++i) {
        cout << v.at(i);
    }
    
}
// Searches the entire puzzle, but may use helper functions to implement logic
void searchPuzzle(const char puzzle[][numCols], const string wordBank[], 
    vector <string> &discovered, int numRows, int numWords);

// Printer function that outputs a vector
void printVector(const vector <string> &v);

int main()
{   int numRows;
    int numWords;
    int i;
    int j;
    char letters;
    // grab the array row dimension and amount of words
    cin >> numWords >> numRows;
    
    // declare a 2D array
    char puzzle[numRows][numCols];
    
    // TODO: fill the 2D array via input
    // read the puzzle in from the input file using cin
    for (i = 0; i < numRows; ++ i) {
        for (j = 0; j < numCols; ++j) {
            cin >> letters;
            puzzle[i][j] = letters;
        }
    }
    
    // create a 1D array for wods
    string wordBank[numWords];
    
    // TODO: fill the wordBank through input using cin
    for ( i = 0; i < numWords; ++i) {
        cin >> letters;
        wordBank[i] = letters;
    }
    // set up discovery vector
    vector <string> discovered;

    // Search for Words
    searchPuzzle(puzzle, wordBank, discovered, numRows, numWords);

    // Sort the results
    sort(discovered.begin(), discovered.end());

    // Print vector of discovered words
    printVector(discovered);

    return 0;
}