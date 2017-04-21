*/
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
*/
#ifndef IOSTREAM_H
#define IOSTREAM_H
#include <iostream>
#endif
#include "classOctagon.h"
; // VS bitches if this isn't here
using namespace std;

int main ()
{

	int g_inputBuffer = 0;
	int g_goAgain = 1;


	while(g_goAgain)
	{
		// Create Object
		ClassOctagon newOctagon;

		cout << endl<< "Please enter size of the octagon: ";

		// Read size and set in object

		cin >> g_inputBuffer;
		newOctagon.setSize(g_inputBuffer);

		// Print options for fillings

		cout << endl
				<< "Please enter type of octagon"	<< endl
				<< "	1: clear"					<< endl
				<< "	2: filled"					<< endl
				<< "	3: horizontal lines"		<< endl
				<< "	4: vertical lines"			<< endl
				<< "	5: crossed lines"			<< endl 
				<< "Option: ";

		// Read type and set in object

		cin >> g_inputBuffer;
		newOctagon.setType(g_inputBuffer);

		// Print Octagon
		newOctagon.display();


		cout << endl << endl 
			<< "Draw another octagon?" << endl
			<< "	1: Yes" << endl
			<< "	0: No" << endl
			<< "Option: ";
		cin >> g_goAgain;
		// set control for while loop
	}
	return 0;
}
