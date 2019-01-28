#include <iostream>
#include <string>
using namespace std; 

bool palindrom_erkennung(string text) {
	// einzelne elemente des Strings einlesen & 2 teilen
	string teil1 = "", teil2 = "";
	for (int i = 0; i < text.length() / 2; i++) {
		teil1 += text.at(i);
	}
	for (int i = text.length(); i > text.length() / 2; i--) {
		teil2 += text.at(i-1);
	}
	//falls der 2. teil einen Buchstaben mehr hat, soll dieser bei dem ersten Teil angefügt werden
	if (teil2.length()>teil1.length()){
		teil1 += text.at((text.length() / 2));
	}
	
	//vergleichen der beiden einzelteile
	//1. fall: beide sind exakt gleich
	if (teil1 == teil2) {
		return true; 
	}
	//2. Fall: Unterschiede in Groß- & Kleinbuchstaben soll nicht berücksichtigt werden. 
	else if (teil1 != teil2) {
		for (int i = teil1.length(), k = teil2.length(); i > 0, k > 0; i--, k--) {
			if(int(teil1.at(i-1))==int(teil2.at(k-1))+32 ||int(teil1.at(i-1))==int(teil2.at(k-1))-32 ||int(teil1.at(i-1))==int(teil2.at(k-1))){
				if ((i == 1) && (k == 1)) {
					return true; 
				}
			}
			else {
				return false; 
			}
		}
	}
}

int main() {
	string eingabe = "";
	string text;
	do {
		cout << "Text: ? ";
		getline(cin, eingabe);
		int i = 0;
		text = "";
		while (i < eingabe.length()) {
			
			char bestandteil = eingabe.at(i);
			int t = int(bestandteil);
			if (!(t<65 || (t>90 && t<97) ||(t>122 && t<=127))){
			text += bestandteil; 
			}
			i++;
		}
	} while (eingabe != text);

   //Bedingung: nur Buchstaben, sonst
	// Aufforderung zur neuen Eingabe
	// rausfinden, ob es falsche Eingaben gibt

	// einsetzen des textes in Funktion
	//Ausgabe, ob Eingabe ein Palindrom ist 
	if (palindrom_erkennung(text) == true) {
		cout << "Das eingegebene Wort ist ein Palindrom.";
	}
	else {
		cout << "Das eingegebene Wort ist KEIN Palindrom.";
	}
	cout << endl; 
	system("PAUSE");
	return 0; 
}