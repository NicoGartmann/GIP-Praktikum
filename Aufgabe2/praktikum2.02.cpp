#include <iostream>
using namespace std; 

int main() {

	double c = 0., f = 0.; //c= celsius, f= fahrenheit
	cout << "Bitte geben Sie die Temperatur in Grad Celsius ein: ? ";
	cin >> c;
	f = c*1.8 + 32;
	cout << "Die Temperatur in Fahrenheit lautet: " << f << endl;
	system("PAUSE");
}