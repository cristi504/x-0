

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

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

	void design(char v[3][3])
	{
			
		cout << "_______"<<endl;
		for (int i = 0; i < 3; i++)
		{
			cout << "|";
			for (int j = 0; j < 3; j++)
			{
				cout << v[i][j];
				cout << "|";
			}
			cout << endl;
			cout << "-------" << endl ;
			

		}
		
	}
	int win(char v[3][3], char player)
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
				cout << "Playerul " << player << " a castigat";
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
				cout << "Playerul " << player << " a castigat";
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
			cout << "Playerul " << player << " a castigat";
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
			cout << "Playerul " << player << " a castigat";
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

		// Afisam pozitiile libere de pe tabla (cu x si y)
		for (int i = 0; i < index; i++) 
		{
			cout << "(" << pozitiiLibere[i].x << " , " << pozitiiLibere[i].y << " )" << endl;
		}

		// Selectam un index random din vectorul de obiecte
		int randomIndex = rand() % index;

		cout << "Indexul ales random este: " << randomIndex<<endl;

		// Selectam obiectul de pe pozitia random aleasa
		return pozitiiLibere[randomIndex];
	}


	/*int primaLocatieLiberaX(char v[3][3])
	{
		for (int i = 0; i < 3; i++)
		{
			
			for (int j = 0; j < 3; j++)
			{
				if (v[i][j] == ' ')
					return i;			
			}
		}
	}

	int primaLocatieLiberaY(char v[3][3])
	{
		for (int i = 0; i < 3; i++)
		{

			for (int j = 0; j < 3; j++)
			{
				if (v[i][j] == ' ')
					return j;
			}
		}
	}*/


	int evaluareJoc(char v[3][3])
	{
		int rezultat = 0;

		rezultat = win(v, 'x');
		if (rezultat == 1)
			cout << "x e castigator";
		else
			cout << "nu e";
		rezultat = win(v, '0');
		if (rezultat == 1)
			cout << "0 e castigator";
		else
			cout << "nu e";

	}
};

int main()
{
	srand(time(NULL));

	xsi0 b;
	char player1, player2;
	int linie, coloana, calculatorX, calculatorY, rezultat;
	
	char v[3][3]=  { { ' ', ' ' ,' '},
					 { ' ', ' ', ' ' },
					 { ' ', ' ' ,' '} };


	//citesc caracterul cu care vreau sa joc, stabilesc celalalt caracter pentru calculator
	
	cout << "Who do you want to be?: ";
	cin >> player1;
	
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
			break;
		}

		cout << "introduce coordinates: ";
		cin >> linie >> coloana;
		v[linie][coloana] = player1;
		b.design(v);

		rezultat = b.win(v, player1);

		if (rezultat == 1) 
		{
			break;
		}

		Coordonate coordonateCalc = b.coordonateCalculator(v);

		v[coordonateCalc.x][coordonateCalc.y] = player2;
		b.design(v);
		
		rezultat = b.win(v, player2);

		if (rezultat == 1)
		{
			break;
		}

		miscari += 2;
	}		
	
	return 0;
}


// x-> 0, 2
// y-> 1, 2


// elemente -> 0  2
// indecsi  -> 0, 1