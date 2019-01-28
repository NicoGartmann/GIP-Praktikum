#include <iostream>
#include <string>
using namespace std;

int main() {

	string text = "";
	int v = 0;
	//1. Eingabe
	cout << "Bitte geben Sie den zu verschluesselnden Text ein: ";
	getline(cin, text);
	cout << "Bitte geben Sie die Anzahl Verschiebepositionen ein (als positive ganze Zahl): ";
	cin >> v;
	//2. Umwandeln des Textes
	for (int i = 0; i < text.length();i++) {
		int d = 0;
		d = int(text.at(i));
        //Prüfung ob der Wert ein Kleinbuchstabe ist 
		if (97 <= d || d >= 122) {
			// durch 26 teilen um auch größere werte für v einsetzen zu können
			v = v % 26;
			d = v + d;
			//wrap-around
			if (d > 122) {
				// hilfsvariable e wird dazu verwendet um die stellen ab anfang des alphabets ausfindig zu machen
				int e = 0;
				e = d - 122;
				d = e + 96;
			}
			cout << char(d);
		}
		//Prüfung ob der Wert ein Großbuchstabe ist
		else if (65 <= d || d >= 90) {
			v = v % 26;
			d = v + d;
			if(d>90){
				//e kann hier erneut verwendet werden, da die "Existenz" von e nach beenden der bed. aus Z. 24 wieder gelöscht wird
				int e = 0;
				e = d - 90;
				d = e + 64;
			}
			cout << char(d);
		}
		//ansonsten Stelle unverändert ausgeben
		else {
			cout << text.at(i);
		}
		
	}
	cout << endl;
	system("PAUSE");
	return 0;

	//

}