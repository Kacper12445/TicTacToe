#include <iostream>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <cstdlib>
#include "Board.cpp"
#include "Player.cpp"
#include "Field.cpp"
#include "Game.cpp"

using namespace std;


int main()
{
    Game g;
    Field field;
    bool turn = false; 
    int size, pts;
    
    Player P1('O');
    Player PC('X');

    cout<<"Size: ";
    cin>>size;
    cout<<"Point to win: ";
    cin>>pts;

    while(!g.Setting_Control(size, pts))
    {
        cout<<"Size: ";
        cin>>size;
        cout<<"Point to win: ";
        cin>>pts;
    }
    
    Board board(size, pts);
    turn = g.Firts_turn();

    cout<<"Clean Board"<<endl;
    board.Draw();

    
    while(!board.Win(P1.get_character(), false) && !board.Win(PC.get_character(), false) && !board.If_Remis(false))
    {
        if(!turn)
        {
            cout<<"Player turn: "<<endl;
            if(P1.Move(board, P1))
            {
                turn = true;
            }
                
        }
        else if(turn)
        {
            cout<<"Computer turn: "<<endl;
            field = PC.Computer(board, P1, PC);
            PC.set_c(board,field.get_x(),field.get_y());
            turn = false;
        }

        board.Draw();
     
    }
}