#include "gameBoard.hpp"
#include "getChar.hpp"
#include<curses.h>
#include <iostream>
#include <ctime>

int main(int argc, char *argv[] ){
bool useDefault = true;
int w = 40;
int h = 20;
int clw;
int clh;
if(argc == 3){
  clh = strtol(argv[1],NULL,10);
  clw = strtol(argv[2],NULL,10);
  if(clh > 9 && clh < 26 && clw > 9 && clw < 79)
    useDefault = false;
}

if( ! useDefault ){
  h = clh;
  w = clw;
}

gameBoard theGame(h,w);
srand (time(NULL));
char c;
theGame.cursesStartup();
theGame.fillGamePool();
cell newHead;
newHead.x = (theGame.getHeight() - 2)/2;
newHead.y = (theGame.getWidth() - 2)/2;
theGame.initSnek(newHead);
theGame.drawBorder();
theGame.updateScore(0);
theGame.putMunchie();

while( (c = get_char()) != 'q' ){
  cell tmp = theGame.getSnekHead();
  mvaddch(tmp.x, tmp.y, '0');
  switch (c){
    case 'h': tmp.y -= 1; break ;
    case 'l': tmp.y += 1; break ;
    case 'k': tmp.x -= 1; break ;
    case 'j': tmp.x += 1; break ;
    case ' ': continue;
  }

  if( theGame.getCellVal(tmp) == - 1){
    theGame.terminate();
    //TODO
    std::cout << "It's Game Over Man, score: " << theGame.score;
    exit(1);
  }
  theGame.mvSnek( tmp );

}
theGame.destroyBoard();
theGame.terminate();
};
