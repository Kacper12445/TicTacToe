#pragma once


class Board
{
	friend class Player;
    char **board;
	int size;
	int points;
	
	public:
	Board(int S, int P):size(S), points(P)
	{
		std::cout<<"Set Size: "<<size<<std::endl;
		std::cout<<"Set Points: "<<points<<std::endl;
		Alocate();
		Clear();
	}
	~Board()
	{
		Delete();
	}
	
	void Alocate();
	void Clear();
	void Delete ();

	bool Is_Available(int i, int j);
	bool Is_Character(int i, int j, char c);
	

	void Draw();
	bool Control_Rows(char c);
	bool Control_Columns(char c);
	bool Control_Diagonal(char c);
	bool Win(char c, bool silence);
	int Count_Points(char Human, char Oponnent);
	bool If_Remis(bool silence);
	bool Firts_turn();
	
};