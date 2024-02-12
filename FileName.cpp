

#include <iostream>
using namespace std;
class xsi0 {
public:

	void design(char v[3][3])
	{
			
		cout << "__________"<<endl;
		for (int i = 0; i < 3; i++)
		{
			cout << "| ";
			for (int j = 0; j < 3; j++)
			{
				cout << v[i][j];
				cout << "| ";
			}
			cout << endl;
			cout << "__________" << endl ;
			

		}
		
	}
};
int main()
{
	xsi0 b;
	char v[3][3] = { { ' ', ' ' ,' '},
					 { ' ', ' ', ' ' },
					 { ' ', ' ' ,' '} };
	b.design(v);
		
	
	return 0;
}