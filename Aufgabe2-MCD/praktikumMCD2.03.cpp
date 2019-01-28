#include <iostream>
using namespace std; 

int main()
{
	char buchstabe; 
	int pos = 0; 

	cout << "Bitte geben Sie den Buchstaben ein: ? "; cin >> buchstabe; 
	pos = int(buchstabe) - (int('a') - 1);
	cout << "Der Buchstabe " << buchstabe << " hat die Position " << pos << " im Alphabet.\n";
	system("PAUSE"); 
	return 0; 
}