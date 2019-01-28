#include <iostream>
using namespace std; 

int main() { 

	double vorherige_eingabe = 0.0, vorvorherige_eingabe = 0.0;
	double verbrauchswert = 0.;
	double a = 0.;

	for (int i = 0; i <= 1;) {
		double aktuelle_eingabe = 0.0;
		do {
			cout << "Bitte geben Sie den neuen letzten Verbrauchswert ein: ? ";
			cin >> aktuelle_eingabe;
		} while (aktuelle_eingabe < 0);
		if (aktuelle_eingabe != 0 && vorherige_eingabe == 0 && vorvorherige_eingabe == 0) {
			verbrauchswert = aktuelle_eingabe + vorherige_eingabe + vorvorherige_eingabe;
		}
		else {
			a = verbrauchswert;
			verbrauchswert = a + aktuelle_eingabe;
		}
		double durchschnitt = 0.;
		durchschnitt = (aktuelle_eingabe + vorherige_eingabe + vorvorherige_eingabe) / 3;
		vorvorherige_eingabe = vorherige_eingabe;
		vorherige_eingabe = aktuelle_eingabe;
		if (verbrauchswert >= 99) {
			break;
		}
		else {
			cout << "Der bisherige Gesamtverbrauch betraegt " << verbrauchswert << endl; 
			cout << "Der Durchschnitt der letzten drei Verbrauchswerte betraegt " << durchschnitt << endl; 
		}
	}
	system("PAUSE");
	return 0; 
}