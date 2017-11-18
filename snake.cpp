#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
using namespace std;

/* Number of food pellets needed to win */
const int kMaxFood = 20;

/* Constants for the different tile types */
const char kEmptyTile = ' ';
const char kWallTile = '#';
const char kFoodTile = '$';
const char kSnakeTile = '*';

/* struct encoding a point on a 2d grid */
struct pointT{
  int row, col;
  pointT(int x, int y): row(x), col(y) {}; //constructor for my struct
};

/* Struct that holds the relevant game information */
struct gameT{
  vector<string> world;
  int numRows, numCols;

  deque<pointT> snake;
  int dx, dy;

  int numEaten;
};

void LoadWorld(gameT& game, ifstream& input){
  input >> game.numRows, game.numCols;
  game.world.resize(game.numRows);

  input >> game.dx >> game.dy;
  string dummy;
  getline(input, dummy); // so that getline plays well with >>

  for (int row=0; row < game.numRows; row++){
    getline(input, game.world[row]);

    int col = game.world[row].find(kSnakeTile);
    if (col != string:npos)
      game.snake.push_back(pointT(row, col)); //Add the head of the snake
  }

  game.numEaten = 0;
}

ifstream OpenUserFile(ifstream& input){
  while (true) {
    cout << "Enter gamefile name:";
    string filename = GetLine();

    input.open(filename.c_str());
    if (input.is_open()) return input;

    cout << "Sorry, I can't find the file" << filename << endl;
    input.clear();
  }
}


void InitializeGame(gameT& game){
  ifstream input;
  OpenUserFile(input);
  LoadWorld(game, input);
}



int main(){
  gameT game;
  InitializeGame(game);
  RunSimulation(game);
  return 0;
}
