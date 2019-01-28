#include <iostream>
using namespace std; 

int main()
{
	double celsius = 0, fahrenheit = 0; 
	cout << "Bitte geben Sie die Temperatur in Grad Celsius ein: ? "; cin >> celsius; 
	fahrenheit = celsius*1.8 + 32; 
	cout << "Die Temperatur in Fahrenheit lautet: " << fahrenheit << endl; 
	system("pause");
	return 0; 
}