#ifndef functionsPrint_hpp
#define functionsPrint_hpp
#include <iostream>
#include <cmath>
#include <ctime>
#include "SDL_Plotter.h"
#include <fstream>
#include "functionsPrint.hpp"
using namespace std;
#include <stdio.h>
//CLASS RELATED TO PRINTING CHARACTERS
class characterPrint{
public:
    characterPrint(){
        
    }
    
    ifstream inSS;
    int fstreamx;
    int fstreamy;
    int numFont[2500];
    int numIterations = 0;
};
//CLASS RELATED TO UPDATING SCORE;

class score{
public:
    int highScore;
    //number of digits
    int hsDigit1;
    int hsDigit2;
    int currScore;
    int numDigits;
    int Digit2;
    int prospectZero;
    int digit1;
    void checkDigitScore(int& score);
    void setScore(int x);
};
//DECLARATION OF CHARACTER FUNCTION
void printChar(SDL_Plotter& g, characterPrint& character, int numIterations, int basex, int basey, int R =0, int G = 0, int B =0);
//DECLARATION OF FILE FUNCTION
void fileOpen(characterPrint& character, string fileName, int it);
//DECLARATION OF FONT FUNCTION
void plotPixels(SDL_Plotter& x, int iStart, int iStop, int jStart, int jStop, int R = 0, int G = 0, int B = 0,int baseJ = 0, int baseI = 0);
#endif /* functionsPrint_hpp */
