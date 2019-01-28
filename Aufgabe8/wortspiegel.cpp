#include <iostream>
#include <string>
using namespace std; 

void wortspiegel(string &text, int pos)
{
	
	int x1 = 0, x2 = 0;
	bool wort = true;
	//prüfen, ob Anfangswert ein Buchstabe ist
	if (text.at(pos) >= 'a' && text.at(pos) <= 'z' || text.at(pos) >= 'A' && text.at(pos) <= 'Z')
	{
		wort = true;
	}
	else
	{
		wort = false;
	}
	//wenn kein Wort dann einfach so wieder ausgeben. 
	if (wort == false)
	{
		; 
	}
	else
	{
		//stelle ermitteln, wo das Wort anfängt
		int i = 0;
		for (i = pos; i >= 0; i--)
		{
			if (text.at(i) >= 'a' && text.at(i) <= 'z' || text.at(i) >= 'A' && text.at(i) <= 'Z')
				//immer prüfen, ob Element noch ein Buchstabe ist, ansonsten ist das Wort vorbei
			{
				wort = true;
				//laufvariable zur ermittlung der angangszuersetzenden Position im alten Text
				x1--;
			}
			else
			{
				wort = false;
			}
			if (wort == false)
			{
				break;
			}
			if (i < 0)
			{
				break;
			}
		}
		string wort2 = "";
		for (i++; i < text.length(); i++)
		{
			if (text.at(i) >= 'a' && text.at(i) <= 'z' || text.at(i) >= 'A' && text.at(i) <= 'Z')
			{
				wort = true;
				x2++;
			}
			else
			{
				wort = false;
			}
			if (wort == true)
			{
				//speichern des Wortes in einem neuen String 
				wort2 += text.at(i);
			}
			else
			{
				break;
			}
		}

		for (int i = pos, x = 0; x<wort2.length(); i--, x++)
		{
			//an dem letzten buchstaben des ursprungs wortes ersten Buchstaben des neuen Strings einsetzen
			text.at(i + x1 + x2) = wort2.at(x);
		}

	}
	cout << endl;
}

