#include "Player.hpp"

#define Infinity 10000000

void Player::set_c(Board &b, int i, int j)
{
	b.board[i][j] = mark;
}

Field Player::Computer(Board &b, Player p1, Player p2)
{
	Field tmp;
	int BestScore = -Infinity;
	int Result, Depth;
	
	b.Draw();
	tmp.set_x(-10);
	tmp.set_y(-10);
	Depth = (b.size <= 4) ? 6: 4;
	
	for(int i = 0; i < b.size; i++)
	{
		for(int j = 0; j < b.size; j++)
		{
			if(b.Is_Character(i, j, ' '))
			{
				p1.set_c(b, i, j);
				Result = Minimax(b, p1.mark, p2.mark, Depth, false, -Infinity, Infinity);
				b.board[i][j] = ' ';
				if(Result > BestScore)
				{
					tmp.set_x(i);
					tmp.set_y(j);
					BestScore = Result;
				}
			}
		}
	}
	return tmp;
}

int Player::Minimax(Board &b, Player p1, Player p2, int Depth, bool isMaximizing, int alfa , int beta)
{
	int BestScore, Result;		
								
	int Pkt = b.Count_Points(p1.mark, p2.mark);	

	if(b.If_Remis(true) || Depth == 10)		
		return Pkt;
	
	if (Pkt == 10)		
		return Pkt;
	
	if (Pkt == -10)	
		return Pkt;

	if(isMaximizing)	
	{
		BestScore = -Infinity;

		for(int i = 0; i < b.size; i++)
		{
			for(int j = 0; j < b.size; j++)
			{
				if(b.Is_Character(i, j, ' '))
				{
					p1.set_c(b, i, j);
					Result = Minimax(b, p1.mark, p2.mark, Depth, false, -Infinity, Infinity);
					Result = Result - Depth;	
					b.board[i][j] = ' ';			
					BestScore = std::max(BestScore, Result);
					alfa =std::max(alfa, BestScore);
					
					if(beta <= alfa)	
						break;	
				}
			}
		}
		return BestScore;
	}
	else
	{
		BestScore = Infinity;
		for(int i = 0; i < b.size; i++)
		{
			for(int j = 0; j < b.size; j++)
			{
				if(b.Is_Character(i, j, ' '))
				{
					p2.set_c(b, i, j);		
					Result = Minimax(b, p1.mark, p2.mark, Depth +1, true, alfa , beta);	
					Result = Result + Depth;
					b.board[i][j] = ' ';			
					BestScore = std::min(BestScore, Result);
					beta = std::min(BestScore, beta);

					if(beta <= alfa)	
						break;
				}
			}
		}
		return BestScore;	
	}
}

bool Player::Move(Board &b, Player p1)
{
	int i = 0;
	int j = 0;
	std::cout<<"\nChoose row: ";
    std::cin>>i;
    std::cout<<"Choose column: ";
    std::cin>>j;
        
	if(b.Is_Available(i,j))
	{
		p1.set_c(b,i,j);
		return true;
	}	
	else
	{
		std::cout<<"It's occupied, try another one\n";
		return false;
	}
}







