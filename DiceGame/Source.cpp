#include <iostream>
#include <ctime>

using namespace std;

int Coubs(int coub);

int DiceGame(char FirstStep, int tries);

int main() {

	srand(time(NULL));

	int tries;
	char FirstStep;
	
	cout << "Who goes first - User or Computer? (u/c)";
	cin >> FirstStep;

	cout << "Enter count of tries: \n";
	cin >> tries;

	DiceGame(FirstStep, tries);
	
	cout << endl << endl;
	system("pause");
	return 0;
}

int Coubs(int coub) {
	int side_coub = 3;

	switch (coub)
	{
	case 1:
		for (int i = 0; i < side_coub; i++)
		{
			for (int j = 0; j < side_coub; j++)
			{
				if (i == j && i + j == side_coub - 1)			//for 1
					cout << " * ";
				else cout << "   ";
			}
			cout << endl;
		}
		break;
	case 2:
		for (int i = 0; i < side_coub; i++)
		{
			for (int j = 0; j < side_coub; j++)
			{
				if (i == j)
					cout << "   ";
				else if (i + j == side_coub - 1)				// for  2
					cout << " * ";
				else cout << "   ";
			}
			cout << endl;
		}
		break;
	case 3:
		for (int i = 0; i < side_coub; i++)
		{
			for (int j = 0; j < side_coub; j++)
			{
				if (i + j == side_coub - 1)						//for  3
					cout << " * ";
				else cout << "   ";
			}
			cout << endl;
		}
		break;
	case 4:
		for (int i = 0; i < side_coub; i++)
		{
			for (int j = 0; j < side_coub; j++)
			{
				if (j == i && i + j == side_coub - 1)
					cout << "   ";
				else if (j == i || i + j == side_coub - 1)		//for  4
					cout << " * ";
				else cout << "   ";
			}
			cout << endl;
		}
		break;
	case 5:
		for (int i = 0; i < side_coub; i++)
		{
			for (int j = 0; j < side_coub; j++)
			{
				if (i == j || i + j == side_coub - 1)			//for  5
					cout << " * ";
				else cout << "   ";
			}
			cout << endl;
		}
		break;
	case 6:
		for (int i = 0; i < side_coub; i++)
		{
			for (int j = 0; j < side_coub; j++)
			{
				if (j == 0 || j == side_coub - 1)					//for  6
					cout << " * ";
				else cout << "   ";
			}
			cout << endl;
		}
		break;
	}
	return coub;
}

int DiceGame(char FirstStep, int tries) {

	int coub1, coub2, user, comp, sum_user, sum_comp;

	sum_user = 0;
	sum_comp = 0;

	if (FirstStep == 'u')
	{
		user = 0;
		comp = 1;
	}
	else if (FirstStep == 'c')
	{
		comp = 0;
		user = 1;
	}
	else cout << "Wrong answer!";

	for (int i = 0; i < tries; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (j == user)
			{
				coub1 = rand() % 6 + 1;
				coub2 = rand() % 6 + 1;
				cout << endl << "User goes: \n";
				Coubs(coub1);
				cout << "--------\n";
				Coubs(coub2);

				sum_user += coub1 + coub2;
			}
			else if (j == comp)
			{
				coub1 = rand() % 6 + 1;
				coub2 = rand() % 6 + 1;
				cout << endl << "Computer goes: \n";
				Coubs(coub1);
				cout << "--------\n";
				Coubs(coub2);

				sum_comp += coub1 + coub2;
			}
		}
	}

	cout << "User's sum is : " << sum_user << ". Average " << sum_user / tries << endl;
	cout << "Comp's sum is : " << sum_comp << ". Average " << sum_comp / tries << endl << endl;

	(sum_user > sum_comp) ? cout << "User win!" : cout << "Computer win!";
	
	return 0;
}
