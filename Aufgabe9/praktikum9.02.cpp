#include <iostream>
#include <string>
using namespace std; 

int zeichenkette_suchen_rekursiv(string text, string zkette, unsigned int &text_pos, unsigned int text_such_pos = 0, unsigned int zkette_such_pos = 0)
{
	if (text.at(text_such_pos) == zkette.at(zkette_such_pos)) zkette_such_pos++; 
	else zkette_such_pos = 0; 
	if (zkette_such_pos == zkette.length())
	{
		text_pos = text_such_pos+1 - zkette_such_pos;
		return 0;
	}
	else if (text_such_pos == text.length()-1) return -1;
	else 
	{
		text_such_pos++;
		return zeichenkette_suchen_rekursiv(text, zkette, text_pos, text_such_pos, zkette_such_pos);
	}
	
}

int main()
{
	string text = ""; 
	string zkette = "";
	unsigned int text_pos = 0; 

	cout << "Bitte geben Sie den Text ein: "; getline(cin, text);
	cout << "Bitte geben Sie die zu suchende Zeichenkette ein: "; getline(cin, zkette);
	zeichenkette_suchen_rekursiv(text, zkette, text_pos);
	if (zeichenkette_suchen_rekursiv(text, zkette,text_pos) == -1) cout << "Die Zeichenkette '" << zkette << "'ist NICHT in dem Text '" << text << "' enthalten.";
	else if(zeichenkette_suchen_rekursiv(text,zkette,text_pos)==0) cout << "Die Zeichenkette '" << zkette << "' ist in dem Text '" << text << "' enthalten.\nSie startet ab Zeichen " << text_pos << " (bei Zaehlung ab 0).";
	cout << endl; 
	system("pause");
	return 0; 
}