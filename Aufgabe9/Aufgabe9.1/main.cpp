#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string br(string s); 

string b(string s); 

string trimme(string plus);

void spalte_ab_erstem(string eingabezeile, char b , string& erster_teil, string& zweiter_teil) {

	// Stelle des ersten eingegebenen Zeichens finden
	for (int i = 0; i < eingabezeile.length(); i++) {
		if (eingabezeile.at(i) == b) {
			for (i++; i < eingabezeile.length(); i++) {
				zweiter_teil += eingabezeile.at(i);
			}
		}
		else if (eingabezeile.at(i) != b) {
			erster_teil += eingabezeile.at(i);
		}
	}
}

struct Person
{
	string nachname, vorname, geburtsdatum; 
};

Person extrahiere_person(string eingabezeile)
{
	char b; 
	Person p;
	string rest;
	spalte_ab_erstem(eingabezeile, ',', p.nachname, rest);
	spalte_ab_erstem(rest, ',', p.vorname, p.geburtsdatum);
	p.nachname = trimme(p.nachname);
	p.vorname = trimme(p.vorname);
	p.geburtsdatum = trimme(p.geburtsdatum); 
	return p;
}

string trimme(string plus)
{
	string ergebnis = ""; 
	int i = 0, s = plus.length() - 1;
	while (plus.at(i) == ' ')
	{
		char d = plus.at(i); 
		if (d != ' ' || i == plus.length() - 1)
			break; 
		i++; 
	}
	while (i<=s)
	{
		char d = plus.at(i);
		ergebnis += d; 
		i++; 
	}
	return ergebnis; 
}

string br(string s)
{
	s += "<br/>"; 
	return s; 
}

string b(string s)
{
	s = "<b>" + s + "</b>"; 
	return s;
}

string ersetze(string zeile, char zu_ersetzendes_zeichen, string ersatztext) {
	string ergebnis = "";
	for (int a = 0; a < zeile.length(); a++) {
		char d;
		d = zeile.at(a);
		if (d != zu_ersetzendes_zeichen) {
			ergebnis += zeile.at(a);
		}
		else if (d == zu_ersetzendes_zeichen) {
			for (int i = 0; i < ersatztext.length(); i++) {
				ergebnis += ersatztext.at(i);
			}
		}
	}
	return ergebnis;
}

int main()
{
	string eingabezeile;
	fstream datei1, datei2, datei3; 
	string text = ""; 
	string kurztext = ""; 
	string langtext = ""; 
	datei1.open("personendaten.txt", ios::in);
		while(getline(datei1, text)) {
			Person person = extrahiere_person(text);
			kurztext += br(b(person.nachname) + ", " + person.vorname) + "\n"; 
			langtext += br(b(person.vorname + " " + person.nachname) +", " +person.geburtsdatum) + "\n"; 
	}
	datei1.close();

	datei2.open("webseite.html.tmpl", ios::in);
	datei3.open("website.html", ios::out); 
	while (getline(datei2, eingabezeile)) {
		eingabezeile = ersetze(eingabezeile, '%', kurztext);
		eingabezeile = ersetze(eingabezeile, '$', langtext);

		datei3 << eingabezeile + "\n"; 
	}
	datei2.close();
	datei3.close();
	return 0;
}