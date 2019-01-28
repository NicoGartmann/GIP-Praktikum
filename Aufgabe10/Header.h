#include <iostream>
using namespace std;
struct TListenKnoten
{
	int data;
	TListenKnoten *next;
};
void hinten_anfuegen(TListenKnoten* &anker, int wert)
{
	TListenKnoten *neuer_eintrag = new TListenKnoten;
	neuer_eintrag->data = wert;
	neuer_eintrag->next = nullptr;
	if (anker == nullptr)
		anker = neuer_eintrag;
	else
	{
		TListenKnoten *ptr = anker;
		while (ptr->next != nullptr)
			ptr = ptr->next;
		ptr->next = neuer_eintrag;
	}
}
void liste_ausgeben(TListenKnoten * anker)
{
	if (anker == nullptr)
		cout << "Leere Liste." << endl;
	else
	{
		cout << "[ ";
		TListenKnoten *ptr = anker;
		do
		{
			cout << ptr->data;
			if (ptr->next != nullptr) cout << " , ";
			else cout << " ";
			ptr = ptr->next;
		} while (ptr != nullptr);
		cout << "]" << endl;
		
	}
}

void liste_ausgeben_rueckwaerts(TListenKnoten* anker)
{
	

}

void einfuegen(TListenKnoten* &anker, int wert_neu, int vor_wert)
{
	if (vor_wert == anker->data)
	{
		int *anker = new int{ wert_neu };
	}
	else
	{
		hinten_anfuegen(anker, wert_neu);
	}


}
