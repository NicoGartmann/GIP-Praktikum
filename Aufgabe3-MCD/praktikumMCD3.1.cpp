#include <iostream>
using namespace std; 

int main()
{
	int eingabe = 0; 
	cout << "Bitte geben Sie Ihre Studienrichtung ein:\n"
		<< "1: Informatik (INF)\n"
		<< "2: Media and Communications for Digital Business (MCD)\n"
		<< "3: Wirtschaftsinformatik(WI)\n"; 
	cin >> eingabe; 
	if (eingabe == 1)
	{
		cout << "Sie studieren Informatik."; 
	}
	else if (eingabe == 2)
	{
		cout << "Sie studieren Media and Communications for Digital Business.";
	}
	else if(eingabe ==3)
	{
		cout << "Sie studieren Wirtschaftsinformatik."; 
	}
	else
	{
		cout << "Falsche Eingabe."; 
	}
	
	cout << endl; 
	system("pause");
	if (eingabe == 1 || eingabe == 2 || eingabe == 3)
	{
		return 0; 
	}
	else
	{
		return 1; 
	}
}