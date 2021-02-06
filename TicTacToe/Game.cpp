#include"Game.hpp"


bool Game::Setting_Control(int size, int points)
{
	bool foo = true;
	if(points > size)
	{
        std::cout<<"Amounts of points cannot be bigger than size. Try again"<<std::endl;
		foo = false;
	}
	if(points < 2)
	{
		std::cout << "To small amount of points. Try again"<<std::endl;
		foo = false;
	}
	if(size < 2)
	{
		std::cout << "Size is too small. Try again"<<std::endl;
		foo = false;
	}
	return foo;
}


bool Game::Firts_turn()
{
	char choice;
	bool x = true;
	bool t;
	while(x)
	{
		std::cout<<"Who start the game: H - Human/ C - Computer ";
		std::cin>>choice;
		if(choice == 'H')
		{
			t = false;
			x = false;
		}
		else if(choice == 'C')
		{
			t = true;
			x = false;
		}
		else
		{
			std::cout<<"There's mistake in your answer. Try Again\n";
		}
	}
	return t;
}
