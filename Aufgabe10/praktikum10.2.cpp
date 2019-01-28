#include <iostream>
using namespace std;

struct TListenKnoten {
	int data;
	TListenKnoten *next;
	TListenKnoten *prev;
};

void hinten_anfuegen(TListenKnoten* &anker, int wert) {
	TListenKnoten *neuer_eintrag = new TListenKnoten;
	neuer_eintrag->data = wert;
	neuer_eintrag->next = nullptr;
	neuer_eintrag->prev = anker; 
	if (anker == nullptr)
	{
		neuer_eintrag->prev = nullptr;
		anker = neuer_eintrag;

	}
	else {
		TListenKnoten *ptr = anker;
		while (ptr->next != nullptr)
			ptr = ptr->next;
		neuer_eintrag->prev = ptr;
		ptr->next = neuer_eintrag;
		neuer_eintrag->prev = ptr; 

	}
}
void liste_ausgeben(TListenKnoten * anker) {
	if (anker == nullptr)
		cout << "Leere Liste." << endl;
	else {
		cout << "[ ";
		TListenKnoten *ptr = anker;

		do {
			cout << ptr->data;
			if (ptr->next != nullptr)
				cout << " , ";
			else
				cout << " ";
			ptr = ptr->next;
		} while (ptr != nullptr);
		cout << "]" << endl;
	}
}
void liste_ausgeben_rueckwaerts(TListenKnoten* anker) {
	
		TListenKnoten *ptr = anker;
		cout << "[ ";
		while (ptr->next != nullptr)
		{
			ptr = ptr->next;

		}
		while (ptr->prev != nullptr)
		{
			cout << ptr->data << " , ";
			ptr = ptr->prev;
		}
		cout << ptr->data;


		cout << " ]" << endl;

}
void einfuegen(TListenKnoten* &anker, int wert_neu, int vor_wert) {
	TListenKnoten *ptr = anker; 
	if (vor_wert == ptr->data)
	{
       TListenKnoten *neuer_eintrag = new TListenKnoten;
	   neuer_eintrag->data = anker->data;
	   neuer_eintrag->next = anker->next;
	   neuer_eintrag->prev = anker;
	   anker->next = neuer_eintrag;
	   anker->data=wert_neu;
	}
	else
	{

		
		while (ptr->next->data != vor_wert)
		{
			ptr = ptr->next;
			if (ptr->next == nullptr)
			{
				break;
			}
		}

		TListenKnoten *neuer_eintrag = new TListenKnoten;

		neuer_eintrag->data = wert_neu;
		neuer_eintrag->next = ptr->next;
		neuer_eintrag->prev = ptr;

		ptr->next = neuer_eintrag;
	}

}
int main() {
	int laenge = 10;
	TListenKnoten *anker = nullptr;
	for (int i = 0; i < laenge; i++)
		hinten_anfuegen(anker, i * i);
	liste_ausgeben(anker);
	liste_ausgeben_rueckwaerts(anker);

	int wert_neu, vor_wert;
	cout << "Einzufuegender Wert: ";
	cin >> wert_neu;
	cout << "Vor welchem Wert? ";
	cin >> vor_wert;
	einfuegen(anker, wert_neu, vor_wert);
	liste_ausgeben(anker);
	system("PAUSE");
	return 0;
}
