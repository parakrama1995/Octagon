#include<iostream>
#include "Header.h"
using namespace std;
int main()
{
	int size = 0;
	cout << "Enter the size : ";
	cin >> size;
	cout << endl;
	octagon calculator;
	calculator.calculateOctagon(size);

	
	system("pause>nul");
}
