

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

ofstream fout("joc.txt");

class Coordonate {
public:
	int x, y;

	Coordonate() {

	}
 
	Coordonate(int x, int y) {
		// this is a constructor
		this->x = x;
		this->y = y;
	}
};


class xsi0 {
public:

	void design(char v[3][3], string playerName, ostream& stream)
	{
		
		stream << "[" << playerName << "]:"<<endl;

		stream << "_______"<<endl;
		for (int i = 0; i < 3; i++)
		{
			stream << "|";
			for (int j = 0; j < 3; j++)
			{
				stream << v[i][j];
				stream << "|";
			}
			stream << endl;
			stream << "-------" << endl ;
			
		}
		
	}
	int win(char v[3][3], char player, string playerName, ostream& stream)
	{
		

		// Verificare linii
		for (int i = 0; i < 3; i++)
		{
			int x = 0;
			for (int j = 0; j < 3; j++)
			{
				if (v[i][j] != player)
					x = 1;
			}
			if (x == 0)
			{
				stream << playerName << " a castigat";
				return 1;
			}
			//esti castigator daca x este 0 adica x a ramas la fel dupa ce am trecut prin randul 'i'
		}
		// Aici se verifica coloanele
		for (int i = 0; i < 3; i++)
		{
			int x = 0;
			for (int j = 0; j < 3; j++)
			{
				if (v[j][i] != player)
					x = 1;
			}
			if (x == 0)
			{
				stream << playerName << " a castigat";
				return 1;
			}
		}

		//aici verificam diag principala
		int x = 0;

		for (int i = 0; i < 3; i++)
		{
			
			if (v[i][i] != player)
				x = 1;		
		}

		if (x == 0) 
		{
			stream << playerName << " a castigat";
			return 1;
		}
		
		//aici verificam diag secundara
		int y = 0;

		for (int i = 0; i < 3; i++)
		{

			if (v[i][3 - i - 1] != player)
				y = 1;
		}

		if (y == 0)
		{
			stream << playerName << " a castigat";
			return 1;
		}
			
		
		return 0;
	}
	
	Coordonate coordonateCalculator(char v[3][3]) 
	{
		int index = 0;
		Coordonate pozitiiLibere[10];

		// Cautam pozitiile libere de pe tabla
		for (int i = 0; i < 3; i++)
		{

			for (int j = 0; j < 3; j++)
			{
				if (v[i][j] == ' ') 
				{
					pozitiiLibere[index] = Coordonate(i, j);
					index++;
				}	
			}
		}

		// Selectam un index random din vectorul de obiecte
		int randomIndex = rand() % index;

		// Selectam obiectul de pe pozitia random aleasa
		return pozitiiLibere[randomIndex];
	}

};

int main()
{
	srand(time(NULL));

	xsi0 b;
	char player1, player2;
	string playerName;
	int linie, coloana, calculatorX, calculatorY, rezultat;
	
	char v[3][3]=  { { ' ', ' ' ,' '},
					 { ' ', ' ', ' ' },
					 { ' ', ' ' ,' '} };


	//citesc caracterul cu care vreau sa joc, stabilesc celalalt caracter pentru calculator
	
	cout << "Enter your name: ";
	fout << "Enter your name: "<<endl;
	cin >> playerName;
	fout << playerName<<endl;

	cout << "Enter the character you want to play with (x or o): ";
	fout << "Enter the character you want to play with (x or o): "<<endl;
	cin >> player1;
	fout << player1<<endl;
	
	if (player1 == 'x')
		player2 = '0';
	else
		player2 = 'x';

		
	int miscari = 0;
	

	while (1)
	{
		if (miscari == 9) 
		{
			cout << "Remiza!";
			fout << "Remiza!"<<endl;
			break;
		}

		cout << "introduce coordinates: ";
		fout << "introduce coordinates: "<<endl;
		
		cin >> linie >> coloana;
		fout << linie << coloana<<endl;
		
		if (v[linie][coloana] != ' ') 
		{
			cout << "The position is already taken, please use another one" << endl;
			fout << "The position is already taken, please use another one" << endl;
		}
		else
		{
			v[linie][coloana] = player1;

			b.design(v, playerName, cout);
			b.design(v, playerName, fout);

			rezultat = b.win(v, player1, playerName, cout);
			rezultat = b.win(v, player1, playerName, fout);

			if (rezultat == 1)
			{
				break;
			}

			Coordonate coordonateCalc = b.coordonateCalculator(v);

			v[coordonateCalc.x][coordonateCalc.y] = player2;

			b.design(v, "Computer", cout);
			b.design(v, "Computer", fout);

			rezultat = b.win(v, player2, "Computer", cout);
			rezultat = b.win(v, player2, "Computer", fout);

			if (rezultat == 1)
			{
				break;
			}

			miscari += 2;
		}
	}		

	fout.close();
	
	return 0;
}
