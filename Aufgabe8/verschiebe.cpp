#include <iostream>
#include <string>
using namespace std; 

void rechts(string text, int &pos)
{
	if (pos == text.length() - 1)
	{
		//wenn pos ganz rechts ist, kann er nicht mehr rechts gehen
		pos;
	}
	else
	{
		//eine position nach rechts 
		pos++;
	}
	cout << endl;
}

void links(string text, int &pos)
{
	if (pos == 0)
	{
		//wenn pos ganz links ist, kann er nicht mehr links gehen 
		pos;
	}
	else
	{
		//eine position nach links 
		pos--;
	}
	cout << endl;
}