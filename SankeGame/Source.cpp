#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include<iomanip>
#include<string.h>
#include<conio.h>
#include<Windows.h>
using namespace std;
//--------------- proprties-----------------
enum Direction { Top =1 , Down, Right , Left  };
class Snake { public: int HeadX, HeadY, Tale_L; Direction Dir; };
class Map { public: int Width, Height, FruitX, FruitY; };
class Player {public: int Score; bool Lose; };
//------------------------------------------
Map Map1; Snake Snake1; Player Player1;

void AddFruit() {
                srand(time(NULL));
                Map1.FruitX = rand() % (Map1.Width - 2) + 1;
                Map1.FruitY = rand() % (Map1.Height - 2) + 1;
}
void Draw() {
                system("cls");
                //width
                for (int i = 0; i < Map1.Height; i++) {
                                //hegiht
                                for (int j = 0; j < Map1.Width;j++) {
                                                if (i == 0 || i == Map1.Height - 1)
                                                                cout << "*";
                                                else if (j == 0 || j == Map1.Width - 1)
                                                                cout << "*";
                                                else if (i == Snake1.HeadY && j == Snake1.HeadX)
                                                                cout << "O";
                                                else if (i == Map1.FruitY && j == Map1.FruitX)
                                                                cout << "$";
                                                else
                                                                cout << " ";
                                }
                                cout << endl;
                }
                cout << "Score = " << Player1.Score;
}
void setup() {
                
                Map1.Width = 40;
                Map1.Height = 20;
                Snake1.Tale_L = 1;
                Snake1.HeadX = Map1.Width / 2;
                Snake1.HeadY = Map1.Height / 2;
                Player1.Score = 0;
                Player1.Lose = false;
                AddFruit();
                Draw();
                Snake1.HeadY++;
                
                
}
void input() {
                if (_kbhit()) {
                                char c = _getch();
                                switch (c)
                                {
                                case 'w':Snake1.Dir=Top;break;
                                case's':Snake1.Dir=Down;break;
                                case'd':Snake1.Dir=Right;break;
                                case'a':Snake1.Dir=Left;break;
                                case'x':exit(0);
                                default:
                                                break;
                                }
                }
}
void Move() {
                switch (Snake1.Dir)
                {
                case Top: Snake1.HeadY--;break;
                case Down:Snake1.HeadY++;break;
                case Right:Snake1.HeadX++;break;
                case Left:Snake1.HeadX--;break;
                default:
                                break;
                }
                if (Snake1.HeadX == Map1.FruitX && Snake1.HeadY == Map1.FruitY) {
                                AddFruit();
                                Player1.Score++;
                                Snake1.Tale_L++;

                }
                if (Snake1.HeadX == Map1.Width-1 || Snake1.HeadX == 0 || Snake1.HeadY == Map1.Height-1 || Snake1.HeadY == 0) {

                                Player1.Lose = true;

                }
}

int main() {
                char input0;
                do {
                                cout << "######## Snake Game ##########" << endl;
                                cout << "press anything to Start the Game " << endl;
                                _getch();
                                setup();
                                while (!Player1.Lose) {
                                                Draw();
                                                input();
                                                Move();
                                                Sleep(100);

                                }
                                system("cls");
                                cout << "########## GAME OVER ############" << endl;
                                cout << "Score = " << Player1.Score << endl;
                                cout << "input x to stop the game " << endl;
                                cout << "press any thing to start the game" << endl;
                                cin >> input0;
                                
                } while (input0 != 'x');



                return 0;
}
