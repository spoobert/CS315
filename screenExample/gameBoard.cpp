#include "gameBoard.hpp"
#include <curses.h>
#include "cell.hpp"
#include <queue>
#include <iostream>
#include <ctime>


void gameBoard::drawBorder( ){
  move(0,0);
  addstr("Snek");
  move(0,_width - 9);
  addstr("score:");
  //top border

  for(int i = 4; i < _width - 8 ; i ++ ){
    addstr("_");
    move(0,i);
  }
  //move(0,_width - 2);
  //addstr("  ");
  //left border
  move(1,0);
  for(int i = 1; i < _height; i++){
    addstr("|");
    move(i,0);
  }
  //right border
  move(1, _width - 1);
  for(int i = 1; i < _height; i++){
    addstr("|");
    move(i,_width - 1);
  }
  //bottom border
  move(_height - 1,0);
  for(int i = 1; i < _width + 1; i++){
    addstr("#");
    move(_height - 1,i);
  }
  refresh();
}

void gameBoard::fillGamePool(){

  _gamePool = new int*[_height];

  for( int row = 0; row < _height; row++)
    _gamePool[row] = new int[_width];

  _freePool = new cell[ (_width - 2 ) * (_height - 2) + 1 ];
//fill columns then move to next row

  for( int i = 0; i < _width; i++){
    _gamePool[0][i] = -1;
    _gamePool[_height - 1][i] = -1;

  }

  for( int i = 1; i < _height - 1; i ++){
    _gamePool[i][0] = -1;
    _gamePool[i][_width - 1] = -1;
  }


  for(int row = 1; row < (_height - 1); row++)
    for(int col = 1; col < (_width - 1) ; col++){
      _gamePool[row][col] = _lastIndex;
      _freePool[_lastIndex].x = row;
      _freePool[_lastIndex].y = col;
      _lastIndex++;
    }

}


void gameBoard::drawSnake( ){

}
/*
lastIdx = 16
lastCell points to 15
freepool has size 17 = lastIdx so last element is 16idx
*/

void gameBoard::initSnek(cell newHead ){
  _snek.push(newHead);
  //swap new and lastIdx on GB
  _gamePool[_freePool[_lastIndex].x][_freePool[_lastIndex].y] = _gamePool[newHead.x][newHead.y];
  _gamePool[newHead.x][newHead.y] = - 1;
  // faux swap new and last in fp
  _freePool[_gamePool[newHead.x][newHead.y]] = _freePool[_lastIndex--];
}


void gameBoard::cursesStartup( void )
{
     initscr();	 /* activate the curses */
     curs_set(0);/* do not display the cursor */
     clear();	 /* clear the screen that curses provides */
     noecho();	 /* prevent the input chars to be echoed to the screen */
     cbreak();	 /* change the stty so that characters are delivered to the
		    program as they are typed--no need to hit the return key!*/
}

void gameBoard::terminate( void )
{
     mvcur( 0, COLS - 1, LINES - 1, 0 );
     clear();
     refresh();
     endwin();
}

void gameBoard::mvSnek( cell newHead ){
  if( newHead.x == munchLoc.x && newHead.y == munchLoc.y){
    growCount += munchVal;
    updateScore(munchVal);
    putMunchie();
  }

  _snek.push(newHead);
  int newHeadIdx = _gamePool[newHead.x][newHead.y];
  _gamePool[newHead.x][newHead.y] = - 1;

  if( growCount == 0 ){
    cell tail = _snek.front();
    _snek.pop();
    mvaddch( tail.x, tail.y, ' ');
    _gamePool[tail.x][tail.y] = newHeadIdx;
    _freePool[newHeadIdx] = tail;
  }
  else {
    cell lastCell = _freePool[_lastIndex];
    _gamePool[lastCell.x][lastCell.y] = newHeadIdx;
    _freePool[newHeadIdx] = lastCell;
    --_lastIndex;
    --growCount;
  }

  mvaddch(newHead.x,newHead.y,'@');
  refresh();
}



cell gameBoard::getSnekHead(){
  return _snek.back();
}

int gameBoard::getSnekX(){
  return _snek.front().x;
}
int gameBoard::getSnekY(){
  return _snek.front().y;
}

int gameBoard::getTailX(){
  return _snek.back().x;
}
int gameBoard::getTailY(){
  return _snek.back().y;
}
void gameBoard::printFP(){
  for(int i = 0; i < (_width - 2)*(_height - 2); i++){
    std::cout << _freePool[i].x << _freePool[i].y << std::endl;
  }
}
void gameBoard::printGB(){

  for(int row = 0; row < _height; row++){
    for(int col = 0; col < _width; col++){
      std::cout<< _gamePool[row][col] <<" ";

    }
    std::cout << std::endl;
  }
}

void gameBoard::destroyBoard(){
  delete [] _gamePool;

}

void gameBoard::putMunchie(){
 int munchIdx = rand() % (_lastIndex + 1);
 munchVal = rand() % 9 + 1;
 munchLoc = _freePool[munchIdx];
 mvaddch(munchLoc.x, munchLoc.y, '0' + munchVal);
 }

int gameBoard::getCellVal( cell tmp ){
  return _gamePool[tmp.x][tmp.y];
}

cell gameBoard::getFreePool( int idx ){
  return _freePool[idx];
}

void gameBoard::updateScore(int newScore ){
  char buffer[4];
  score += newScore;

  int rng = snprintf(buffer, 4, "%d", score);
  int w = _width;
  for(int i = 0; i < rng ; i ++){
    mvaddch(0,w - 3, buffer[i]);
    w++;
  }
  refresh();
}
