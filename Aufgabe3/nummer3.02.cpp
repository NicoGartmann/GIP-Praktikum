#include <iostream>
using namespace std;

int main() {
	int erste = 0, zweite = 0, dritte = 0, vierte = 0, fuenfte = 0, kleinste = 0, groesste = 0;
	//Anfangstext mit Aufforderung zur Zahleingabe
	cout << "Bitte geben Sie die 1. Zahl ein: ";
	cin >> erste;
	cout << "Bitte geben Sie die 2. Zahl ein: ";
	cin >> zweite;
	cout << "Bitte geben Sie die 3. Zahl ein: ";
	cin >> dritte;
	cout << "Bitte geben Sie die 4. Zahl ein: ";
	cin >> vierte;
	cout << "Bitte geben Sie die 5. Zahl ein: ";
	cin >> fuenfte;
	// Suche der kleinsten Zahl
	// Vergleich 1. mit 2., zuweisung erste = kleinste oder 2. 
	if (erste < zweite) {
		kleinste = erste;
	}
	else {
		kleinste = zweite;
	}
	// vergleich kleinste mit 3., neuzuweisung oder keine Änderung
	if (kleinste < dritte) {
		kleinste = kleinste;
	}
	else {
		kleinste = dritte;
	}
	// Vergleich kleinste mit 4., neuzuweisung oder keine Änderung
	if (kleinste < vierte) {
		kleinste = kleinste;
	}
	else {
		kleinste = vierte;
	}
	//Vergleich kleinste mit 5., neuzuweisung oder keine Änderung
	if (kleinste < fuenfte) {
		kleinste = kleinste;
	}
	else {
		kleinste = fuenfte;
	}
	//Ausgabe kleinste Zahl + Stelle

	if (erste == kleinste) {
		cout << "Die 1. Zahl war die kleinste der eingegebenen Zahlen und lauten: " << erste << endl;
	}
	else if (zweite == kleinste) {
		cout << "Die 2. Zahl war die kleinste der eingegebenen Zahlen und lautet: " << zweite << endl;
	}
	else if (dritte == kleinste) {
		cout << "Die 3. Zahl war die kleinste der eingegebenen Zahlen und lautet: " << dritte << endl;
	}
	else if (vierte == kleinste) {
		cout << "Die 4. Zahl war die kleinste der eingegebenen Zahlen und lautet: " << vierte << endl;
	}
	else if (fuenfte == kleinste) {
		cout << "Die 5. Zahl war die kleinste der eingegebenen Zahlen und lautet: " << fuenfte << endl;
	}


	//Suche der groessten Zahl
	//Vergleich 1. mit 2., zuweisung größere in groesste
	if (erste > zweite) {
		groesste = erste;
	}
	else {
		groesste = zweite;
	}
	// Vergleich groesste mit 3., neuzuweisung oder keine Änderung
	if (groesste > dritte) {
		groesste = groesste;
	}
	else {
		groesste = dritte;
	}
	// vergleich groesste mit 4., neuzuweisung oder keine Änderung
	if (groesste > vierte) {
		groesste = groesste;
	}
	else {
		groesste = vierte;
	}
	// verlgeich groesste mit 5., neuzuweisung oder keine Änderung
	if (groesste > fuenfte) {
		groesste = groesste;
	}
	else {
		groesste = fuenfte;
	}

	//ausgabe groesster Zahl + stelle 
	if (erste == groesste) {
		cout << "Die 1. Zahl war die groesste der eingegebenen Zahlen und lautet: " << erste << endl;
	}
	else if (zweite == groesste) {
		cout << "Die 2. Zahl war die groesste der eingegebenen Zahlen und lautet: " << zweite << endl;
	}
	else if (dritte == groesste) {
		cout << "Die 3. Zahl war die groesste der eingegebenen Zahlen und lautet: " << dritte << endl;
	}
	else if (vierte == groesste) {
		cout << "Die 4. Zahl war die groesste der eingegebenen Zahlen und lautet: " << vierte << endl;
	}
	else if (fuenfte == groesste) {
		cout << "Die 5. Zahl war die groesste der eingegebenen Zahlen und lautet: " << fuenfte << endl;
	}
	system("PAUSE");
	return 0;
}