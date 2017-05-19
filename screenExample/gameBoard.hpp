#ifndef GAMEBOARD_HPP
#define GAMEBOARD_HPP
#include "cell.hpp"
#include <queue>

class  gameBoard {
public:
  gameBoard(int row, int col): _width(col), _height(row), _dimension(row*col), _lastIndex(0), score(0),growCount(7){}
  void drawBorder(void);
  void drawSnake(void);
  void cursesStartup(void);
  void terminate(void);
  int getDimension( ) {return _dimension;}
  int getHeight( ) {return _height;}
  int getWidth( ) {return _width;}
  void fillGamePool();
  void initSnek(cell);
  cell getSnekHead();
  int getSnekX();
  int getSnekY();
  int getTailX();
  int getTailY();
  void printFP();
  void printGB();
  void destroyBoard();
  void mvSnek( cell );
  void putMunchie();
  cell getFreePool(int);
  int getCellVal(cell);
  void updateScore(int);
  int score;

private:
  cell *_freePool;
  std::queue<cell> _snek;
  const int _dimension;
  const int _width;
  const int _height;
  int _lastIndex;
  int **_gamePool;
  cell munchLoc;
  int munchVal;
  int growCount;
};

#endif
