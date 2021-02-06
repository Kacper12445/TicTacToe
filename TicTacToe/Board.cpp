#include "Board.hpp"
void Board::Alocate()
	{
		board = new char*[size];
		for(int i = 0; i < size; i++)
		{
			board[i] = new char[size];
		}
	}
void Board::Clear()
	{
		for(int i = 0; i < size; i++)
		{
			for(int j = 0; j < size; j++)
			{
				board[i][j] = ' ';
			}
		}
	}
void Board::Delete ()
	{
		for(int i = 0; i < size; i++)
		{
			delete[] board[i];
		}

		delete board;
	}

bool Board::Is_Available(int i, int j)
{
    bool test = (board[i][j] == ' ') ? true : false;
	
	return test;   
}
bool Board::Is_Character(int i, int j, char c)
{	
	bool test = (board[i][j] == c) ? true : false;
	
	return test;
}
void Board::Draw()
{	
	int number_of_fields = pow(size, 2);
	for(int i = 0; i < size; i++)	
	{
		for(int j = 0; j < size; j++)	
		{
			std::cout << " " << board[i][j] << " ";	
			if(((j+1) % size))
				std::cout <<	"|";				
			else if(((i+1)*(j+1)) != number_of_fields)	
			{
				for(int j = 0; j < size; j++)	
				{
					if(j == 0) 
						std::cout << "\n";	
					std::cout<<"---";		
					if(j != size-1)	
						std::cout<<"+";
					if(j == size-1)	
						std::cout<<"\n";
				}
			}
			else 
				std::cout<<std::endl;
		}
	}

}
bool Board::Control_Rows(char c)
{
	bool test = false;
	int counter = 0;
	
	for(int i = 0; i < size; i++)
	{
		counter = 0;			
		int j = 0;				
		for(int k = 0; k < size-1; k++)
		{
			if(board[i][j+k] == board[i][j+k+1] && board[i][j+k] == c)
			{
				counter++;		

				if(counter == (points-1))				
					test = true;
			}
			else
				counter = 0;
			
		}
		
	}

	return test;		
}
bool Board::Control_Columns(char c)
{
	bool test = false;	
	int counter = 0;	
	
	for(int j = 0; j < size; j++)
	{
		counter = 0;			
		int i = 0;				
		for(int k = 0; k < size-1; k++)
		{
			if(board[i+k][j] == board[i+k+1][j] && board[i+k][j] == c) 
			{
				counter++;		

				if(counter == (points-1))	
					test = true;
			}
			else
				counter = 0;	
		}
	}

	return test;		
}
bool Board::Control_Diagonal(char c)
{
	bool test = false;	
	int counter = 0;	

			for(int i = size-2; i >= 0; i--)
			{
				counter = 0;
				int j = 0;
				for	(int k = 0; k <= size; k++)
				{
					if((k+1+i) > (size-1) || (k+1+j) > (size-1))	
					{
						counter = 0;
					}
					else
					{
						if(board[i+k][j+k] == board[i+k+1][j+k+1] && board[i+k][j+k] == c)	
						{
							counter++;
						
							if(counter == (points-1))
								test = true;
						}
						else
							counter = 0;
					}
				}
			}
//---------------------------------------------------------------------------------
			for (int j = 1; j <= size-2; j++)		
			{
				counter = 0;					
				int i = 0;

				for	(int k = 0; k <= size; k++)
				{
					if((k+1+i) > (size-1) || (k+1+j) > (size-1))	
					{
						counter = 0;

					}
					else
					{
						if(board[i+k][j+k] == board[i+k+1][j+k+1] && board[i+k][j+k] == c)	
						{
							counter++;
	
							if(counter == (points-1))
								test = true;
						}
						else
							counter = 0;
					}
				}
			}

//---------------------------------------------------------------------------------

			for(int i = 1; i <= (size-1); i++)	
			{
				counter = 0;						
				int j = size-1;
				
				for	(int k = 0; k <= size; k++)
				{
					if((k+1+i) > (size-1) || (j-k-1) < 0)
					{
						counter = 0;
					}
					else
					{
						if(board[i+k][j-k] == board[i+k+1][j-k-1] && board[i+k][j-k] == c)
						{
							counter++;
						
							if(counter == (points-1))
								test = true;
						}
						else
							counter = 0;
					}
				}
			}

//---------------------------------------------------------------------------------

			for(int j = 1; j <= (size-1); j++)		
			{
				int i = 0;
				counter = 0;
				for	(int k = 0; k <= size; k++)
				{
					if((k+1+i) > (size-1) || (j-k-1) < 0)
					{
						counter = 0;
					}
					else
					{
						if(board[i+k][j-k] == board[i+k+1][j-k-1] && board[i+k][j-k] == c)
						{
							counter++;
						
							if(counter == (points-1))
								test = true;
						}
						else
							counter = 0;
					}
				}
			}

	return test;	
}

bool Board::Win(char c, bool silence)
{
	if(Control_Rows(c) || Control_Columns(c) || Control_Diagonal(c))
	{
		if(!silence)
		{
			Draw();
			std::cout<<"\nPlayer "<< c <<" won!!!\n\n";
		}
		return true;
	}
	else	
		return false;
}

int Board::Count_Points(char Human, char Opponent)
{
	if (Win(Human , true))
		return 10;
	else if (Win(Opponent, true))
		return -10;
	else 
		return 0;
}

bool Board::If_Remis(bool silence)
{
	for (int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)	
		{
			if(Is_Character(i, j, ' '))	
				return false;
		}
	}

	if(!silence)	
	{
		Draw();	

		std::cout<<"\nRemis !!!\n\n";	
	}
	return true;
}




