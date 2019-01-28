#include <iostream>
#include <string>
using namespace std; 

int main() {

	int stunden = 0, minuten = 0, taktzeit = 0;
	//Eingabe von Startzeit und Taktzeit unter Berücksichtigung von Fehlereingaben -> erneute Aufforderung zur Eingabe 
	do {
		cout << "Bitte geben Sie die Stunden der Startuhrzeit ein: ";
		cin >> stunden;
	} while (stunden <0 || 23 <stunden);
	do {
		cout << "Bitte geben Sie die Minuten der Startuhrzeit ein: ";
		cin >> minuten;
	} while (minuten <0 || 59 < minuten);
	cout << "Der erste Bus faehrt also um " << stunden << ":" << minuten << " Uhr." << endl; 
	do {
		cout << "Bitte geben Sie die Taktzeit in Minuten ein: ";
		cin >> taktzeit;
	} while (taktzeit < 0 || 180 < taktzeit);
	// startuhrzeit ist erster Fahrtermin, also zu Beginn direkt ausgeben 
	cout << stunden << ":" << minuten << " ";
	
	// erstellen des Busplans
	// kleiner 24, da ein tag nur 24 std. hat 
	while(stunden < 24){
		// taktzeit ist in minuten also vorerst mit minuten verrechnen
		minuten += taktzeit;
		// für Fälle die nach Mitternacht eintreten, soll er abbrechen
		if (minuten >= 60 && stunden == 23) {
			break;
		}
		// wenn minuten anzahl 60 erreicht oder überschreitet, sollen stunden hinzugefügt werden 
		else if (minuten >= 60) {
			cout << endl; 
			//hilfsvariable i zur bestimmung der zu addierenden stunden 
			int i = minuten / 60;
			minuten = minuten % 60; 
			stunden= stunden + i;
			cout << stunden << ":" << minuten  << " ";
		}
		else { cout << stunden << ":" << minuten << " ";
		}
	}
	cout << endl;
	system("PAUSE");
	return 0;
}