#include <iostream>
using namespace std;

int main()
{
	
	char b; //b=buchstabe
	int p = 0;  //p=position
	cout << "Bitte geben Sie den Buchstaben ein: ?";
	cin >> b;
	p = int(b) - int('a') + 1;
	cout << "Der Buchstabe " << b << " hat die Position " << p << " im Alphabet\n";
	system("PAUSE");
}