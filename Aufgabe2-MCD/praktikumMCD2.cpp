#include <iostream>
using namespace std; 

int main()
{
	int eingabe = 0; 

	cout << "Bitte geben Sie Ihre Studienrichtung ein:\n" << "1: Informatik (INF)\n" << "2: Media and Communications for Digital Business (MCD)\n" << "3: Wirtschaftsinformatik (WI)\n"; 
	cout << "Ihre Eingabe: ? "; cin >> eingabe; 
	if (eingabe == 1)
	{
		cout << "Ihre Eingabe lautete: Informatik (INF)" << endl;
	}
	else if (eingabe == 2)
	{
		cout << "Ihre Eingabe lautete: Media and Communications for Digital Business (MCD)" << endl; 
	}
	else if (eingabe == 3)
	{
		cout << "Ihre Eingabe lautete: Wirtschaftsinformatik (WI)" << endl; 
	}
	else
	{
		cout << "Falsche Eingabe du Wichser!" << endl; 
	}
	system("pause");
	return 0; 
}