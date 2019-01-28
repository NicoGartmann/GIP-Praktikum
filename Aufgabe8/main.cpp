#include <iostream>
#include <string>
#include "wortspiegel.h"
#include "verschiebe.h"
using namespace std; 



void sternchen(int &pos)
{
	string pos2 = "";
	if (pos == 0) {
		//sternchen für die pos. stelle
		cout << "*";
	}
	else
	{
		for (int i = 0; i <= pos - 1; i++)
		{
			//soviele leertasten bis vor dem sternchen 
			pos2 += " ";
		}
		cout << pos2 << "*";
	}
	cout << endl;
}



int main()
{
	string text = ""; 
	int pos = 0;
	char befehl;

	cout << "Bitte geben Sie den Text ein: ? "; getline(cin, text); 
	
	for (int i = 0; i < 1;)
	{
		cout << text << endl; 
		sternchen(pos);
		cout << "Befehl (l: links, r: rechts, s: spiegeln, q: Ende) ?- "; cin >> befehl; 

		if (befehl == 'q') 
		{
			break; 
		}
		else if (befehl == 'r') 
		{
			rechts(text, pos);
		}
		else if(befehl == 'l')
		{

			links(text, pos);
		}
		else if (befehl == 's')
		{
			wortspiegel(text, pos);
		}
	}
	system("pause");
	return 0; 
}