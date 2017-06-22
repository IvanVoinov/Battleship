#include <clocale>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>

// ������������� ������ �����������: �������������� � ������������
enum direction { h, v };

class player
{
public:
	bool defeat_flag; // ���������� ������ ���������� � ���������
	int hits[10][10]; // ������ "���������" �������
	int ships[10][10]; // ������ �������� �������

	player() : defeat_flag(0) {} // �����������

	void ships_init();
	void set(int deck);
	int place_ship(int s, int c, direction dir, int deck);
	void turn(player&, int character, int digit);
	void turn(player&);
};

// ����� �������� � 13 ����� � 29 ��������
const int s = 13, c = 29;
char map[s][c] = {
	"  ABCDEFGHIJ     ABCDEFGHIJ ",
	" ############   ############",
	"0#          #  0#          #",
	"1#          #  1#          #",
	"2#          #  2#          #",
	"3#          #  3#          #",
	"4#          #  4#          #",
	"5#          #  5#          #",
	"6#          #  6#          #",
	"7#          #  7#          #",
	"8#          #  8#          #",
	"9#          #  9#          #",
	" ############   ############" };

player human;
player computer;

struct Position
{
private:
	const int x;
	const int y;
public:
	Position(int x, int y) : x(x), y(y) { }
	int getY() { return y; }
};

void map_init(char map[s][c]);
void show(char map[s][c]);
int input(char&, char&);
void test();
int check_ending();

char numbers[10] = { '0','1','2','3','4','5','6','7','8','9' };

int main()
{
	setlocale(LC_CTYPE, "Russian");
	int message = 0; // ���������� ������ ���� ���������

					 // ��������� ���������� �������� ���������� ��������� �����
	srand(static_cast<unsigned int>(time(NULL)));

	human.ships_init(); // ������������� �������� ��������
	computer.ships_init(); // ������������� �������� ����������
	map_init(map); // ���������� � ������ map ��������� ��� human.ships

				   /*
				   message ����� ��������� ��� ��������:
				   0 - �� ���������
				   1 - ������������ ����� �������� �������
				   2 - ���-�� �������, ����� ����
				   */
	while (message != 2)
	{
		int user_input = 0;
		system("cls"); // ������� ������
		show(map);     // ����� �� ����� map
		if (message == 1) // ��� ��������� 1 - ������� �������� ��������
			std::cout << "�� ����� �������� ��������!\n";
		message = 0;   // ��������� message
					   //test();      // ������� ��� ������������ �������� ships � hits

		char character, digit;
		user_input = input(character, digit); // !!!���������� ���������� �� ������
		if (user_input == 1)
		{
			message = 1;
			continue;
		}

		human.turn(computer, character, digit);
		computer.turn(human);
		message = check_ending();
	}
	_getch();
	return 0;
}

/*
���������� � ������ map ���������� �� human.ships.
*/
void map_init(char map[s][c])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (human.ships[i][j] == 2)
				map[i + 2][j + 2] = 219;
		}
	}
}

/*
������� � ������ maps ��������� ���������� � ��������� ���������
������������.
����� ���������� ����� �� ����� map. ��� ���� ������������
������� ships � hits ������ player.
*/
void show(char map[s][c])
{
	for (int i = 0; i<10; i++)
	{
		for (int j = 0; j<10; j++)
		{
			/* ��������� ���� ������ */
			if (computer.hits[i][j] == 1 && human.ships[i][j] == 3)
			{
				map[i + 2][j + 2] = '�';
			}
			else if (computer.hits[i][j] == 1 && human.ships[i][j] != 3)
			{
				map[i + 2][j + 2] = '�';
			}

			/* ��������� ���� ���������� */
			if (computer.ships[i][j] == 3 && human.hits[i][j] == 1)
			{
				map[i + 2][j + 2 + 15] = '�';
			}
			else if (computer.ships[i][j] != 3 && human.hits[i][j] == 1)
			{
				map[i + 2][j + 2 + 15] = 'O';
			}
		} // ����� for j
	} //����� for i

	  // ������������ ����� ������� map �� �����
	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < c; j++)
		{
			std::cout << map[i][j];
		}
		std::cout << "\n";
	}
}



// ���� ���������
int input(char& character, char& digit)
{
	character = _getche(); // ���� "��������������" ����������
	int match = 0;
	for (char i = 0; i < 10; i++)
		if (numbers[i] == character)
		{
			match = 1;

			character = i;
		}
	if (match == 0)
		return 1;
	std::cout << '-';
	match = 0;
	digit = _getche(); // ���� "������������" ����������
	for (int i = 0; i < 10; i++)
		if (numbers[i] == digit)
		{
			match = 1;
			digit = i;
		}
	if (match == 0)
		return 1;
	return 0;
}

void test()
{
	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			std::cout << human.hits[i][j];
		}
		std::cout << "  ";
		for (int j = 0; j < 10; j++)
		{
			std::cout << computer.hits[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			std::cout << human.ships[i][j];
		}
		std::cout << "  ";
		for (int j = 0; j < 10; j++)
		{
			std::cout << computer.ships[i][j];
		}
		std::cout << std::endl;
	}
}

// � ������� ��������������� � ����������� ����� defeat_flag �������.
int check_ending()
{
	int flag = 0;
	int human_flag = 0;
	int computer_flag = 0;
	for (int i = 0; i<10; i++)
	{
		for (int j = 0; j<10; j++)
		{
			if (human.ships[i][j] == 2)
				human_flag = 1; // � ������������ ��� �������� ������������� �������
			if (computer.ships[i][j] == 2)
				computer_flag = 1; // � ���������� ��� �������� ������������� �������
		}
	}
	if (human_flag == 0)
		flag = 2;
	if (computer_flag == 0)
		flag = 1;
	if (flag == 1)
	{
		std::cout << "������� �����!\n";
		return 2;
	}
	if (flag == 2)
	{
		std::cout << "������� ���������!\n";
		return 2;
	}
}

void player::ships_init()
{
	// ������������� �������� hits � ships
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j< 10; j++)
		{
			ships[i][j] = 1;
			hits[i][j] = 0;
		}
	}

	// ��������� ��������
	set(4);
	set(3);
	set(3);
	set(2);
	set(2);
	set(2);
	set(1);
	set(1);
	set(1);
	set(1);
}

void player::set(int deck)
{
	int my = deck - 1;
	bool isset = 0;
	int s, c;
	direction dir;
	while (isset == 0) // �������� ������� �� ���������� �������
	{
		dir = static_cast<direction>(rand() % 2); // �������� �����������

		s = rand() % 10; // ��������� ������� ������������ ����������
		c = rand() % 10;
		int e = 0;
		switch (dir)
		{
		case h:
			if (ships[s][c + deck - 1] == 1)
			{
				e = place_ship(s, c, dir, deck); // �������� ������� ������
				if (e == 0)
				{
					for (int i = 0; i < deck; i++)
					{
						ships[s][c + i] = 2; // ��������� ������� � ������� ships
					}
					isset = 1;
				}
			}
			break;
		case v:
			if (ships[s + deck - 1][c] == 1)
			{
				e = place_ship(s, c, dir, deck);
				if (e == 0)
				{
					for (int i = 0; i < deck; i++)
					{
						ships[s + i][c] = 2;
					}
					isset = 1;
				}
			}
			break;
		} // ����� switch
	} // ����� while
} // ����� set4()

  /*
  ������� ���������, ����� �� � ������ ���������� [s][c]
  ���������� ������� � �������� deck.
  � ������������ �������� ����� ������ ����������� ��� ���������
  ��������������� ������� � [4][3]
  */
int player::place_ship(int s, int c, direction dir, int deck)
{
	int e = 0;
	switch (dir)
	{
	case h:
		if (ships[s - 1][c - 1] == 2)
		{
			e = 1;
			/*
			345678
			#-------
			2|X
			3| 2222
			4|
			*/
		}
		if (ships[s - 1][c + deck] == 2)
		{
			e = 1;
			/*
			345678
			#-------
			2|     X
			3| 2222
			4|
			*/
		}
		if (ships[s + 1][c - 1] == 2)
		{
			e = 1;
			/*
			345678
			#-------
			2|
			3| 2222
			4|X
			*/
		}
		if (ships[s + 1][c + deck] == 2)
		{
			e = 1;
			/*
			345678
			#-------
			2|
			3| 2222
			4|     X
			*/
		}

		if (ships[s][c - 1] == 2)
		{
			e = 1;
			/*
			345678
			#-------
			2|
			3|X2222
			4|
			*/
		}
		if (ships[s][c + deck] == 2)
		{
			e = 1;
			/*
			345678
			#-------
			2|
			3| 2222X
			4|
			*/
		}
		for (int i = 0; i < deck; i++)
		{
			if (ships[s - 1][c + i] == 2)
			{
				e = 1;
				/*
				345678
				#-------
				2| XXXX
				3| 2222
				4|
				*/
			}
			if (ships[s + 1][c + i] == 2)
			{
				e = 1;
				/*
				345678
				#-------
				2|
				3| 2222
				4| XXXX
				*/
			}
		}
		break;
	case v:
		if (ships[s - 1][c - 1] == 2)
		{
			e = 1;
			/*
			345678
			#-------
			2|X
			3| 2
			4| 2
			5| 2
			6| 2
			7|
			*/
		}
		if (ships[s - 1][c + 1] == 2)
		{
			e = 1;
			/*
			345678
			#-------
			2|  X
			3| 2
			4| 2
			5| 2
			6| 2
			7| X
			*/
		}
		if (ships[s + deck][c - 1] == 2)
		{
			e = 1;
			/*
			345678
			#-------
			2|
			3| 2
			4| 2
			5| 2
			6| 2
			7|X
			*/
		}
		if (ships[s + deck][c + 1] == 2)
		{
			e = 1;
			/*
			345678
			#-------
			2|
			3| 2
			4| 2
			5| 2
			6| 2
			7|  X
			*/
		}

		if (ships[s - 1][c] == 2)
		{
			e = 1;
			/*
			345678
			#-------
			2| X
			3| 2
			4| 2
			5| 2
			6| 2
			7|
			*/
		}
		if (ships[s + deck][c] == 2)
		{
			e = 1;
			/*
			345678
			#-------
			2|
			3| 2
			4| 2
			5| 2
			6| 2
			7| X
			*/
		}
		for (int i = 0; i < deck; i++)
		{
			if (ships[s + i][c - 1] == 2)
			{
				e = 1;
				/*
				345678
				#-------
				2|
				3|X2
				4|X2
				5|X2
				6|X2
				7|
				*/
			}
			if (ships[s + i][c + 1] == 2)
			{
				e = 1;
				/*
				345678
				#-------
				2|
				3| 2X
				4| 2X
				5| 2X
				6| 2X
				7|
				*/
			}
		}
		break;
	}
	return e;
}

// ��� ����������: ������ ��������� � ������� human.ships � computer.hits
void player::turn(player& enemy)
{
	//srand(static_cast<unsigned int>(time(NULL)));
	bool flag = 0;
	while (flag == 0)
	{
		int character = rand() % 10; // ���������� �� ������� ����� �������� ���������
		int digit = rand() % 10;     // ���������� ��������
		if (hits[character][digit] != 1) // ��������: ������� �� ��� ��������� ��� ����������
		{
			hits[character][digit] = 1;
			flag = 1;
			if (enemy.ships[character][digit] == 2)
			{
				enemy.ships[character][digit] = 3;
			}
		}
	}
}

// ��� ������: ������ ��������� � ������� computer.ships � human.hits
void player::turn(player& enemy, int character, int digit)
{
	hits[character][digit] = 1;
	if (enemy.ships[character][digit] == 2)
	{
		enemy.ships[character][digit] = 3;
	}
}