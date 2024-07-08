#include "functionsPrint.hpp"
using namespace std;
const int NUM_ROW = 800;
const int NUM_COL = 800;
const int SIZE = 25;
enum Direction {UP,DOWN,LEFT,RIGHT};


int main(int argc, char ** argv) {
    score snakeScore;
    bool isPaused = false;
    char key;
    int tenCount = 0;
    int length = 3;
    ofstream outSS;
    ifstream inSS;
    SDL_Plotter g(1000,1000);
    int xLoc[1600], yLoc[1600];
    Direction dir = RIGHT;
    int speed = 75;
    int diff = 12;
    int letterArrayCount = 0;
    snakeScore.setScore(0);
    snakeScore.prospectZero = 0;
    snakeScore.highScore = -1;
    int saveCount = 0;
    bool startGame = false;
    bool isSave = false;
    bool isDead = false;
    xLoc[0] = NUM_COL/2;
    xLoc[1] = NUM_COL/2 - SIZE;
    yLoc[0] = NUM_ROW/2;
    yLoc[1] = NUM_ROW/2;
    int numIterations = 0;
    //font test;

    srand(time(0)); //GENERATES LOCATION OF FOOD
    int randRow = (rand()%885)+90;
    int randCol = (rand()%885)+90;
    g.initSound("Minecraft-death-sound.wav");
    g.initSound("Minecraft-eating-sound.wav");
    characterPrint c0,c1,c2,c3,c4,c5,c6,c7,c8,c9,cS,cC,cO,cR,cE,cSemi;
    characterPrint cH, cI,cG, cP, cT, cA;
    fileOpen(c0,"0.txt", numIterations);
    fileOpen(c1,"1.txt", numIterations);
    fileOpen(c2,"2.txt", numIterations);
    fileOpen(c3,"3.txt", numIterations);
    fileOpen(c4,"4.txt", numIterations);
    fileOpen(c5,"5.txt", numIterations);
    fileOpen(c6,"6.txt", numIterations);
    fileOpen(c7,"7.txt", numIterations);
    fileOpen(c8,"8.txt", numIterations);
    fileOpen(c9,"9.txt", numIterations);
    fileOpen(cS,"S.txt", numIterations);
    fileOpen(cC,"C.txt", numIterations);
    fileOpen(cO,"O.txt", numIterations);
    fileOpen(cR,"R.txt", numIterations);
    fileOpen(cE,"E.txt", numIterations);
    fileOpen(cH,"H.txt", numIterations);
    fileOpen(cI,"I.txt", numIterations);
    fileOpen(cG,"G.txt", numIterations);
    fileOpen(cP,"P.txt", numIterations);
    fileOpen(cT,"T.txt", numIterations);
    fileOpen(cA,"A.txt", numIterations);
    fileOpen(cSemi,"semi.txt", numIterations);
    inSS.open("saveScores.txt");
    outSS.open("saveScores.txt");
    

    
    while(!g.getQuit()) { //MASTER GAME LOOP
        if(isDead == true) {
            length = 3;
            speed = 75;
            for(int i = 0; i < 100; i++) {
                for(int j = 0; j < 100; j++) {
                    g.plotPixel(rand()%1000,rand()%1000,0,0,rand()%50);
                }
            }
            printChar(g,cH,cH.numIterations,80,400,0,160);
            printChar(g,cI,cI.numIterations,140,400,0,160);
            printChar(g,cG,cG.numIterations,200,400,0,160);
            printChar(g,cH,cH.numIterations,260,400,0,160);
            printChar(g,cS,cS.numIterations,340,400,0,160);
            printChar(g,cC,cC.numIterations,400,400,0,160);
            printChar(g,cO,cO.numIterations,460,400,0,160);
            printChar(g,cR,cR.numIterations,520,400,0,160);
            printChar(g,cE,cE.numIterations,580,400,0,160);
            printChar(g,cSemi,cSemi.numIterations,660,400,0,160);

            snakeScore.checkDigitScore(snakeScore.currScore);
            if(snakeScore.currScore >= snakeScore.highScore) {
                snakeScore.highScore = snakeScore.currScore-1;
            }
            if(snakeScore.hsDigit1== 0) {
                printChar(g,c0,c0.numIterations,780,400,0,160);
            }
            if(snakeScore.hsDigit1 == 1) {
                printChar(g,c1,c1.numIterations,780,400,0,160);
            }
            if(snakeScore.hsDigit1 == 2) {
                printChar(g,c2,c2.numIterations,780,400,0,160);
            }
            if(snakeScore.hsDigit1 == 3) {
                printChar(g,c3,c3.numIterations,780,400,0,160);
            }
            if(snakeScore.hsDigit1 == 4) {
                printChar(g,c4,c4.numIterations,780,400,0,160);
            }
            if(snakeScore.hsDigit1 == 5) {
                printChar(g,c5,c5.numIterations,780,400,0,160);
            }
            if(snakeScore.hsDigit1 == 6) {
                printChar(g,c6,c6.numIterations,780,400,0,160);
            }
            if(snakeScore.hsDigit1 == 7) {
                printChar(g,c7,c7.numIterations,780,400,0,160);
            }
            if(snakeScore.hsDigit1 == 8) {
                printChar(g,c8,c8.numIterations,780,400,0,160);
            }
            if(snakeScore.hsDigit1 == 9) {
                printChar(g,c9,c9.numIterations,780,400,0,160);
            }
            
            
            if(snakeScore.hsDigit2== 0) {
                printChar(g,c0,c0.numIterations,720,400,0,160);
            }
            if(snakeScore.hsDigit2 == 1) {
                printChar(g,c1,c1.numIterations,720,400,0,160);
            }
            if(snakeScore.hsDigit2 == 2) {
                printChar(g,c2,c2.numIterations,720,400,0,160);
            }
            if(snakeScore.hsDigit2 == 3) {
                printChar(g,c3,c3.numIterations,720,400,0,160);
            }
            if(snakeScore.hsDigit2 == 4) {
                printChar(g,c4,c4.numIterations,720,400,0,160);
            }
            if(snakeScore.hsDigit2 == 5) {
                printChar(g,c5,c5.numIterations,720,400,0,160);
            }
            if(snakeScore.hsDigit2 == 6) {
                printChar(g,c6,c6.numIterations,720,400,0,160);
            }
            if(snakeScore.hsDigit2 == 7) {
                printChar(g,c7,c7.numIterations,720,400,0,160);
            }
            if(snakeScore.hsDigit2 == 8) {
                printChar(g,c8,c8.numIterations,720,400,0,160);
            }
            if(snakeScore.hsDigit2 == 9) {
                printChar(g,c9,c9.numIterations,720,400,0,160);
            }
            
            
            
            snakeScore.currScore = -1;
            g.update();
            if(g.kbhit()){
                        key = toupper(g.getKey());
                       switch(key){
                           case SDLK_SPACE:
                               startGame = true;
                               xLoc[0] = NUM_COL/2;
                               xLoc[1] = NUM_COL/2 - SIZE;
                               
                               yLoc[0] = NUM_ROW/2;
                               yLoc[1] = NUM_ROW/2;
                               speed = 75;
                               isDead = !isDead;
                       }
            }
        } else {
        if(!startGame) {
            plotPixels(g,0,1000,0,1000,0,160);
        
            //PRINTS WORD "PRESS"
            printChar(g,cP,cP.numIterations,200,400);
            printChar(g,cR,cR.numIterations,260,400);
            printChar(g,cE,cE.numIterations,320,400);
            printChar(g,cS,cS.numIterations,380,400);
            printChar(g,cS,cS.numIterations,440,400);
            //PRINTS WORD "SPACE"
            printChar(g,cS,cS.numIterations,520,400);
            printChar(g,cP,cP.numIterations,580,400);
            printChar(g,cA,cA.numIterations,640,400);
            printChar(g,cC,cC.numIterations,700,400);
            printChar(g,cE,cE.numIterations,760,400);
            //PRINTS WORD "TO"
            printChar(g,cT,cT.numIterations,320,460);
            printChar(g,cO,cO.numIterations,380,460);

            //PRINTS WORD "START"
            printChar(g,cS,cS.numIterations,460,460);
            printChar(g,cT,cT.numIterations,520,460);
            printChar(g,cA,cA.numIterations,580,460);
            printChar(g,cR,cR.numIterations,640,460);
            printChar(g,cT,cT.numIterations,700,460);
        }
        if(g.kbhit()){
                    key = toupper(g.getKey());
                   switch(key){
                       case SDLK_SPACE:
                           startGame = true; //RESTARTS GAME IF SPACEBAR IS PRESSED
                           
                           if(isDead) {
                               isDead = false;
                               startGame = false;
                           }
                       case 'W' :
                           if(dir != DOWN) { //ENSURES SNAKE CANT GO INSIDE ITSELF
                               dir = UP;
                           }
                                            break;
                       case 'S' :
                           if(dir != UP) {//ENSURES SNAKE CANT GO INSIDE ITSELF
                               dir = DOWN;
                           }
                                            break;
                           
                       case 'A' :
                           if(dir != RIGHT) {//ENSURES SNAKE CANT GO INSIDE ITSELF
                           dir = LEFT;
                       }
                                            break;
                       case 'D' :
                           if(dir != LEFT) {//ENSURES SNAKE CANT GO INSIDE ITSELF
                               dir = RIGHT;
                           }
                                            break;
                       case 'P' :
                           isPaused = !isPaused;
                                            break;
                       case 'O' :
                           while(saveCount == 0) {
                           isSave = true;
                            saveCount++;
                           }
                           saveCount = 0;
                           break;
                
                   }
        }
            if(isSave) {
                outSS << snakeScore.currScore;
                break;
            }
            g.update();
            if(startGame) {
        //GENERATES BACKROUND
        plotPixels(g, 0, 1000, 0, 1000,0,160);
        plotPixels(g,70,91,0,1000); //GENERATES BORDER
                                    //BETWEEN SCORE AND GAME
        if(!isPaused) { //CHECKS IF GAME IS NOT PAUSED
            
        //MOVING OF SNAKE
        for(int i = length - 1; i > 0; i--){
                xLoc[i] = xLoc[i-1]; //DELETES SNAKE MOVEMENT
                yLoc[i] = yLoc[i-1];
            }
            switch(dir){
                case RIGHT : xLoc[0] += SIZE;
                            break;
                    
                case LEFT  : xLoc[0] -= SIZE;
                            break;
                    
                case UP    : yLoc[0] -= SIZE;
                            break;
                    
                case DOWN  : yLoc[0] += SIZE;
                            break;
            }
        //PLOTS SNAKE
        for(int i = 0; i < length; i++) {
            for(int y = 0; y < SIZE; y++) {
                for(int x = 0; x < SIZE; x++) {
                    g.plotPixel (xLoc[i] + x, yLoc[i]+ y, 0,0,0);
                
                }
            }
        }
        //PREVENTS SNAKE LEAVING 1000X1000 PLOTTER
        if(xLoc[0] > 1000 || xLoc[0] < 0 ||yLoc[0] > 1000 || yLoc[0] < 90) {
            isDead = true;
            g.playSound("Minecraft-death-sound.wav"); //PLAYS DEATH SOUND
        }
        
        //CHECKS IF FOOD EATEN
        if(xLoc[0]  > randRow -(SIZE-1) && xLoc[0]  < randRow + (SIZE-1) && yLoc[0]  > randCol - (SIZE-1) && yLoc[0]  < randCol + (SIZE-1)) {
            randRow = (rand()%885)+90; //CHANGES FOOD LOCATION
            randCol = (rand()%885)+90;
            g.playSound("Minecraft-eating-sound.wav"); //PLAYS FOOD SOUND
            length += 1; //INCREASES LENGTH
            speed--;
            snakeScore.checkDigitScore(snakeScore.currScore);
        }
            //PRINTS FOOD
            plotPixels(g, 0, SIZE, 0 ,SIZE,220,0,0,randRow,randCol);
            //CHECKS IF SNAKE GOES INSIDE ITSELF
            for(int d = 3; d <= length; d++) {
                if(xLoc[0]+12 >= xLoc[d]- diff && xLoc[0]+12 <= xLoc[d]+ diff && yLoc[0]+12 >= yLoc[d]- diff && yLoc[0]+12 <= yLoc[d]+ diff) {
                    isDead = true; //KILLS SNAKE IF INSIDE ITSELF
                    g.playSound("Minecraft-death-sound.wav"); //PLAYS DEATH SOUND
                }
            }
            
            //PRINTS WORD "SCORE:" IN TOP LEFT CORNER
            printChar(g,cS,cS.numIterations,0,0);
            printChar(g,cC,cC.numIterations,60,0);
            printChar(g,cO,cO.numIterations,120,0);
            printChar(g,cR,cR.numIterations,180,0);
            printChar(g,cE,cE.numIterations,240,0);
            printChar(g,cSemi,cSemi.numIterations,300,0);

                    if(snakeScore.currScore < 10) {
                printChar (g,c0,c0.numIterations,360,0);
                    }

                if(snakeScore.digit1== 0) {
                    printChar(g,c0,c0.numIterations,420,0);
                }
                if(snakeScore.digit1 == 1) {
                    printChar(g,c1,c1.numIterations,420,0);
                }
                if(snakeScore.digit1 == 2) {
                    printChar(g,c2,c2.numIterations,420,0);
                }
                if(snakeScore.digit1 == 3) {
                    printChar(g,c3,c3.numIterations,420,0);
                }
                if(snakeScore.digit1 == 4) {
                    printChar(g,c4,c4.numIterations,420,0);
                }
                if(snakeScore.digit1 == 5) {
                    printChar(g,c5,c5.numIterations,420,0);
                }
                if(snakeScore.digit1 == 6) {
                    printChar(g,c6,c6.numIterations,420,0);
                }
                if(snakeScore.digit1 == 7) {
                    printChar(g,c7,c7.numIterations,420,0);
                }
                if(snakeScore.digit1 == 8) {
                    printChar(g,c8,c8.numIterations,420,0);
                }
                if(snakeScore.digit1 == 9) {
                    printChar(g,c9,c9.numIterations,420,0);
                }

            
            
            if(snakeScore.Digit2== 0) {
                printChar(g,c0,c0.numIterations,360,0);
            }
            if(snakeScore.Digit2 == 1) {
                printChar(g,c1,c1.numIterations,360,0);
            }
            if(snakeScore.Digit2 == 2) {
                printChar(g,c2,c2.numIterations,360,0);
            }
            if(snakeScore.Digit2 == 3) {
                printChar(g,c3,c3.numIterations,360,0);
            }
            if(snakeScore.Digit2 == 4) {
                printChar(g,c4,c4.numIterations,360,0);
            }
            if(snakeScore.Digit2 == 5) {
                printChar(g,c5,c5.numIterations,360,0);
            }
            if(snakeScore.Digit2 == 6) {
                printChar(g,c6,c6.numIterations,360,0);
            }
            if(snakeScore.Digit2 == 7) {
                printChar(g,c7,c7.numIterations,360,0);
            }
            if(snakeScore.Digit2 == 8) {
                printChar(g,c8,c8.numIterations,360,0);
            }
            if(snakeScore.Digit2 == 9) {
                printChar(g,c9,c9.numIterations,360,0);
            }

            
        g.update();
        //DETERMINES SPEED OF SNAKE
        g.Sleep(speed); //SETS SPEED OF SNAKE
        numIterations++;
        
            //letterArrayCountC = 0;
            //letterArrayCountS = 0;
        } // <---- END OF isPaused IF STATEMENT
            } //<------ Startgame Loop
        } // <--- isDead loop
    
    } //<----- END OF getQuit LOOP
    
}// <------- ENDING BRACE
