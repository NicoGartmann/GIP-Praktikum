#include <iostream>
using namespace std; 

int main()
{
	int eingabe[5] = { 0 };
	for (int i = 0; i < 5; i++)
	{
		do
		{
			cout << "Bitte geben Sie die " << i + 1 << ". Zahl ein: ? "; cin >> eingabe[i]; 
		} while (eingabe[i] < 1 || eingabe[i]>9);
	}
	for (int i = 0; i < 5; i++)
	{
		cout << i + 1; 
		for (int x = 0; x < eingabe[i]; x++)
		{
			cout << "*"; 
		}
		cout << endl; 
	}
	cout << " 123456789" << endl; 
	system("pause");
	return 0; 
}