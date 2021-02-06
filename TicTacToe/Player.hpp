#pragma once
#include "Board.hpp"
#include "Field.hpp"

class Player
{
    char mark;

    public:
    Player(char C): mark(C){}
    char get_character()const
	{
		return mark;
	}

    void set_c(Board &b, int i, int j);

    Field Computer(Board &b, Player p1, Player p2);
    int Minimax(Board &b, Player p1, Player p2, int Depth, bool isMaximizing, int alfa , int beta);
    bool Move(Board &b, Player p1);
};
