#include <iostream>
using namespace std; 

int main() {

	double eingabe = 0.; int auswahl = 0; double fahrenheit = 0; double dollar = 0; double fuss = 0;
	double ergebnis = 0.;
	cout << "Ihre Eingabe: ?";
	cin >> eingabe;
	cout << "Ihre Auswahl der Umwandlung:" << endl << "1 - Celsius in Fahrenheit" << endl << "2 - Meter in Fuss" << endl << "3 - Euro in US Dollar" << endl;
	cin >> auswahl;
	fahrenheit = eingabe *1.8 + 32;
	dollar = eingabe *1.2957;
	fuss = eingabe * 3.2808;
	ergebnis = fahrenheit*(auswahl - 2)*(auswahl - 3) / 2 +
		fuss*(auswahl - 1)*(auswahl - 3)*-1 +
		dollar*(auswahl - 1)*(auswahl - 2) / 2;
	cout << "Das Ergebnis lautet: " << ergebnis << endl;
	system("PAUSE");
	return 0;
}