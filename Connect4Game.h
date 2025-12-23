#ifndef CONNECT4GAME_H
#define CONNECT4GAME_H
#define PLAYER1 1
#define PLAYER2 2

class Connect4Game{
  int **board,turn, SIZE;
public:
  void initBoard(int);
  void showboard();
  void start();
  int getturn();
  void insertvalue(int);
  void switchturn(int);
  int rowsleft(int);
  bool iswin(int);
  bool boardfull();
  ~Connect4Game();
};

#endif