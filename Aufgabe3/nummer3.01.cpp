#include <iostream>
using namespace std;

int main() {
	int tag1 = 0, monat1 = 0, jahr1 = 0, tag2 = 0, monat2 = 0, jahr2 = 0;
	//Aufforderung zur eingabe
	cout << "Bitte geben Sie den Tag des ersten Datums ein: ";
	cin >> tag1;
	cout << "Bitte geben Sie den Monat des ersten Datums ein: ";
	cin >> monat1;
	cout << "Bitte geben Sie das Jahr des ersten Datums ein: ";
	cin >> jahr1;
	cout << "Bitte geben Sie den Tag des zweiten Datums ein: ";
	cin >> tag2;
	cout << "Bitte geben Sie den Monat des zweiten Datums ein: ";
	cin >> monat2;
	cout << "Bitte geben Sie das Jahr des zweiten Datums ein: ";
	cin >> jahr2;
	//Vergleich ob beide Daten gleich 
	if (tag1 == tag2 && monat1 == monat2 && jahr1 == jahr2) {
		cout << "Beide Datumsangaben sind gleich." << endl;
	}
	// Vergleich ob 1. datum größer 2. datum 
	else if (jahr1 > jahr2 || (jahr1==jahr2 && monat1>monat2) || (jahr1==jahr2 && monat1==monat2 && tag1>tag2) ) {
		cout << "Das erste Datum liegt nach dem zweiten Datum" << endl;
}
// Vergleich ob 1. datum kleiner 2. datum 
	else if (jahr1 < jahr2 || (jahr1 == jahr2 && monat1 < monat2) || (jahr1 == jahr2 && monat1 == monat2 && tag1 < tag2)) {
		cout << "Das erste Datum liegt vor dem zweiten Datum." << endl;
	}
	system("PAUSE");
	return 0;
}