#include "functionsPrint.hpp"
//PRINTS CHARACTER
void printChar(SDL_Plotter& g, characterPrint& character, int numIterations, int basex, int basey, int R , int G, int B) {
    int fstreamx = character.fstreamx;
    int fstreamy = character.fstreamy;
    int x = 0;
    
    for(int i = 0+basey; i < fstreamx+basey; i++) {
        for(int j = 0+basex; j < fstreamy+basex; j++) {
            if(numIterations < 1 ) {
            character.inSS >> character.numFont[x];
            }
            if(character.numFont[x] == 1) {
            g.plotPixel(j,i,R,G,B);
            }
            x++;
        }
    }
    x = 0;
}
//OPENS FILE FOR CHARACTER
void fileOpen(characterPrint& character, string fileName, int it){
    
    character.inSS.open(fileName);
    //checks if file successful
    if(it == 0) {
    character.inSS >> character.fstreamx;
    character.inSS >> character.fstreamy;
    }
}
//UPDATES SCORE ON SCOREBOARD
void score::checkDigitScore(int& score){
    if(score <= 9) {
        numDigits = 1;
        prospectZero = 0;
    }
    else if(score <= 99){
        numDigits = 2;
        prospectZero = -1;
    }
    score++;
    digit1 = currScore%10;
    Digit2 = (score/10)%10;
    hsDigit1 = highScore%10;
    hsDigit2 = (highScore/10)%10;
}
//SETS SCORE
void score::setScore(int x){
    currScore = x;
}
//PLOTS GROUP OF PIXELS
void plotPixels(SDL_Plotter& x, int iStart, int iStop, int jStart, int jStop, int R , int G, int B, int baseJ, int baseI){
    for(int i = iStart; i < iStop; i++) {
        for(int j = jStart; j < jStop; j++) {
            x.plotPixel (j+baseJ, i+baseI, R,G,B);
        }
    }
}
