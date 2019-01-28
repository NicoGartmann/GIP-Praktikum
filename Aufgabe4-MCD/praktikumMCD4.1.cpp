#include <iostream>
#include <string>
using namespace std; 

int main()
{
	string text = "", zaehlen = ""; 
	cout << "Bitte geben Sie den Text ein: ? "; getline(cin, text);
	cout << "Bitte geben sie die zu zaehlenden Zeichen ein: ? "; getline(cin, zaehlen);
	for (int i = 0; i < zaehlen.length(); i++)
	{
		int haeuf = 0;
		for (int x = 0; x < text.length(); x++)
		{ 
			if (zaehlen.at(i) == text.at(x))
			{
				haeuf++; 
			}
			
		}
		cout << "Das Zeichen " << zaehlen.at(i) << " kommt " << haeuf << " mal in dem Text vor.\n"; 
	}
	system("pause");
	return 0; 
}