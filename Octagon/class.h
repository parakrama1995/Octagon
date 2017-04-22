#ifndef IOSTREAM_H
#define IOSTREAM_H
#include <iostream>
#endif
#include "ClassOctagon.h"
using namespace std;

// Public Constructors

ClassOctagon::ClassOctagon (int newSize, int newType)
{
	size = newSize;
	type = newType;
}

ClassOctagon::~ClassOctagon ()
{

}


// Public Setters and Getters for size and type

int ClassOctagon::setSize (int newSize)
{
	size = newSize;
	return 0;
}

int ClassOctagon::getSize ()
{
	return size;
}

int ClassOctagon::setType (int newType)
{
	type = newType;
	return 0;
}

int ClassOctagon::getType ()
{
	return type;
}


// Private functions for printing major sides

int ClassOctagon::printFirstSide ()
{
	// print leading spaces
	for(int j=0;j <= size;j++)
	{
		cout << " ";
	}
	// print first side
	for(int j=0;j < size;j++)
	{
		cout << "_";
	}
	return 0;
}

int ClassOctagon::printSecondSide (int sideLine)
{
	// print leading spaces
	for(int i=sideLine;i < size;i++)
	{
		cout << " ";
	}
	// print second side for this line
	cout << "/";
	// return number of characters printed
	return ((size - sideLine)+1);
}

int ClassOctagon::printSixthSide (int sideLine)
{
	// print leading spaces
	for(int i=0;i < ((size+1)-sideLine);i++)
	{
		cout << " ";
	}
	// print sixth side for this line
	cout << "\\";
	// return number of characters printed
	return ((size - sideLine)+2);
}

int ClassOctagon::printEigthSide ()
{
	// Also prints last line of sixth and seventh sides
	for(int i=0;i < size; i++)
	{
		cout << " ";
	}
	cout << "\\";
	for(int i=0;i < size;i++)
	{
		cout << "_";
	}
	cout << "/";
	return (0);
}


// Private function for printing filling

int ClassOctagon::printFilling (int space)
{

	switch (type)
	{
	case 1 : 
		// clear
		for(int i = 0;i < (size + (2*(space-1)));i ++)
		{
			cout << " ";
		}
		break;

	case 2 :
		// filled
		for(int i = 0;i < (size + (2*(space-1)));i ++)
		{
			cout << "+";
		}
		break;

	case 3 :
		// horizontal lines, toggles with lines variable, 
		// if odd print spaces, if even print lines
		if (line % 2)
			for(int i = 0;i < (size + (2*(space-1)));i ++)
			{
				cout << " ";
			}
		else
			for(int i = 0;i < (size + (2*(space-1)));i ++)
			{
				cout << "-";
			}
			break;

	case 4 :
		// vertical lines, toggles with collumn, 
		// if odd print lines, if even print spaces
		for(int i = 0;i < (size + (2*(space-1)));i ++)
		{
			if (collumn % 2)
			{
				cout << "|";
				collumn ++;
			}
			else
			{
				cout << " ";
				collumn ++;
			}
		}
		break;

	case 5 :
		// crossed lines, two nested toggles on line and collumn, 
		// prints characters according to table below:
		//
		//	line >		|		|  odd	|  even
		//	------------|-------|-------|----------
		//	collumn		|odd	|  " "	|  "-"
		//				|-------|-------|----------
		//				|even	|  "|"	|  "+"
		//	---------------------------------------

		if (line % 2)
			for(int i = 0;i < (size + (2*(space-1)));i ++)
			{
				if (collumn % 2)
				{
					cout << " ";
					collumn ++;
				}
				else
				{
					cout << "|";
					collumn ++;
				}
			}
		else
			for(int i = 0;i < (size + (2*(space-1)));i ++)
			{
				if (collumn % 2)
				{
					cout << "-";
					collumn ++;
				}
				else
				{
					cout << "+";
					collumn ++;
				}
			}
			break;

			// This should never be reached...
	default :
		cout << "ya dun goofed";
		exit (1);
	}
	return 0;
}


//Public function to print octagon

int ClassOctagon::display ()
{
	// Variables used in for loops
	int i = 0;
	int j = 0;

	printFirstSide();
	cout << endl;
	line = 1; // initialise line

	//print second filling and third sides
	for (j = 0;j < size; j++)
	{
		// print second side and leading spaces and 
		// make collumn equal to number of characters printed
		collumn = printSecondSide(j);
		// print filling, what cort is determined by type, line 
		// and collumn class variables
		printFilling((j+1));
		// Print third side
		cout << "\\" << endl;
		line++;
	}


	// print fourth filling and fifth sides
	for(i = 1;i <= size; i++)
	{
		//print fourth side
		cout << "|";
		collumn = 1; // initialise collumn for this line
		// print filling, what cort is determined by type, line 
		// and collumn class variables
		printFilling(size+1);
		//print fifth side
		cout << "|" << endl;
		line ++;
	}

	//print sixth filling and seventh sides minus last line
	for(i = size; i >= 2; i--)
	{
		// print leading spaces and sixth side and make collumn equal to
		// number of characters printed
		collumn = (printSixthSide(i));
		// print filling, what cort is determined by type, line and 
		// collumn class variables
		printFilling(i);
		//print seventh side
		cout << "/" << endl;
		line ++;
	}

	//print eigth side and last lines from sixth and seventh sides

	printEigthSide();

	// return 0 for successful completion

	return 0;
}

class tempc
    : public EmptyClass
    , public Any
{
    //FRIENDS
    friend class Ctrl;
    friend void Vector<int>::Clear();
 
public:
    /*
    * all handling data structures and typedefs nesseccary for the usage of public classes API go here
    */
 
    typedef unsigned HANDLE;
    typedef tempc CLASSNAME;
 
    struct SubStruct
    {}
    
    static const int AnIntConstant = 123;
    //static const float constf = 1.2f; //NOT POSSIBLE, arch dependant.
 
    //CTORS, DTORS, all concerning this class generation
    //INTERFACE, defines how to operate it
 
    //explicit
    tempc(int a = 0);
    virtual ~tempc() {}
 
    void AReadOnlyMethod() const { /*do something, bot dont change things in class*/ }
    void AWritableMethod() { /*here you can change your class state*/ }
 
    /*
    * Here follows the public available data, typically its place for a not close related members
    */
    
protected:
    /*
    * all handling data structures and typedefs interesting for the deriving classes go here
    */
 
    /*
    * Here follows the interface, deriving classes might be interested in, accessing it directly.
    */
    
    /*
    * Here follows the data, which mostly for performance reasons should be made available to derived classes
    */
    
private:
    /*
    * all handling data structures and typedefs which we use only internally, go here
    */
 
    /*
    * Here follows the private interface, which mostly are own helper classes and functions
    */
 
    /*
    * Here follows the private data, which only the class itself takes care of and none should ever know about.
    * in case of wrapper class this is mostly the objects that are wrapped
    */
};
