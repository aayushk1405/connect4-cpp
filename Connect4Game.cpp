#include <iostream>
#include <cstdlib>
#include "Connect4Game.h"
using namespace std;

void Connect4Game::initBoard(int size){
  this->SIZE=size;
  this->board= new int*[size];
  for(int i=0;i<size;i++){
    this->board[i]= new int[size];
    for(int j=0;j<size;j++){
      this->board[i][j]=0;
    }
  }
}

void Connect4Game::showboard(){
  
  for(int r=0;r<SIZE;r++){
    
    cout << "+";
    for(int c=0;c<SIZE;c++){
      cout << "---+";
    }
    cout << "\n";
    
    cout << "|";
    for(int c=0;c<SIZE;c++){
      cout << board[r][c] << "|";
    }
    cout << "\n";
  }
  
  cout << "+";
  for(int c=0;c<SIZE;c++){
    cout << "---+";
  }
  cout << "\n";
  
  cout << " ";
  for(int c=0;c<SIZE;c++){
    cout << c << " ";
  }
  cout << "\n\n";
}

void Connect4Game::insertvalue(int pos){
  if(pos<0 || pos>=SIZE){
    cout << "Invalid Position,Try again!";
    return;
  }
  int row= rowsleft(pos);
  if(row==-1){
    cout << "This Column is full!.\n";
  }
  this->board[rowsleft(pos)][pos]= getturn();
}

void Connect4Game::start(){
  system("clear");
  cout << "\t\t\t***************************\n"
       << "\t\t\t*  Welcome to the Game! *\n"
       << "\t\t\t***************************\n";
  showboard();
  this->turn= PLAYER1;
}

int Connect4Game::getturn(){
  return this->turn;
}

void Connect4Game::switchturn(int player){
  if(player == PLAYER1) this->turn= PLAYER2;
  else this->turn= PLAYER1;
}

int Connect4Game::rowsleft(int pos){
  for(int r = SIZE - 1; r >= 0; r--){
        if(board[r][pos] == 0)
            return r;
  }
  return -1;

}

bool Connect4Game::iswin(int player){
  int i,j,k;
  for(int i=0;i<SIZE;i++){
    for(int j=0;j<SIZE;j++){
      if(this->board[i][j]==player){
        int count=0;
        
        //checking for rows
        for(int k=0;k<4;k++){
          if((i+k)<SIZE && this->board[i+k][j]==player){
            count++;
          }
        }
        if(count==4) return true;
        else count=0;
        
        //checking for columns
        for(int k=0;k<4;k++){
          if((j+k)<SIZE && this->board[i][j+k]==player){
            count++;
          }
        }
        if(count==4) return true;
        else count=0;
        
        //checking for diagonals
        
        for(int k=0;k<4;k++){
          if((i+k)<SIZE && (j+k)<SIZE && this->board[i+k][j+k]==player){
            count++;
          }
        }
        if(count==4) return true;
        else count=0;
        
        
        for(int k=0;k<4;k++){
          if((i-k)>=0 && (j+k)<SIZE && this->board[i-k][j+k]==player){
            count++;
          }
        }
        if(count==4) return true;
        else count=0;
      }
    }
  }
  return false;
}

bool Connect4Game::boardfull(){
  for(int r=0;r<this->SIZE;r++){
    for(int c=0;c<this->SIZE;c++){
      if(board[r][c]==0) return false;
    }
  }
  return true;
}

Connect4Game::~Connect4Game(){
  for(int i=0;i<SIZE;i++) delete[] board[i];
  delete[] board;
}