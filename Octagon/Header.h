#include <iostream>
using namespace std;
class octagon
{
public:
	int calculateOctagon(int size);
};

int octagon::calculateOctagon(int size)

{
	//size = size - 1;
	for (int i = 0, k = size, l = 2 * size - 1; i<size; i++, k--, l++)
	{
		for (int j = 0; j<3 * size; j++) //The Top Part of the Octagon
		{
			if (j >= k && j <= l)
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}
	for (int i = 0; i<size; i++)
	{
		for (int j = 0; j<3 * size; j++)
			cout << "-";
		cout << endl;
	}
	for (int i = 0, k = 1, l = 3 * size - 2; i<size; i++, k++, l--)
	//int i = 0, k = 1, l = 3 * size - 2;
	{
		for (int j = 0; j<3 * size; j++)// Bottom Part of the Octagon
		{
			if (j >= k && j <= l)
				cout << "+";
			else
				cout << " ";
		}
		cout << endl;
	}
	return 0;
}
