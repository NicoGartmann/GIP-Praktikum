#include <iostream>
using namespace std;

int main() {
	int eingabe[5] = { 0 };

	for (int i = 0; i < 5; i++) {
		do {
			cout << "Bitte geben Sie die " << i + 1 << ". Zahl ein: ? ";
			cin >> eingabe[i];
		} while (eingabe[i] < 1 || eingabe[i] > 9);
	}
	for (int i = 0; i < 9; i++) {
		cout << 9-i;
		for (int x = 0; x < 5; x++) {
			if (eingabe[x] == 9 - i) {
				cout << "*";
			}
			else if (eingabe[x] > 9 - i) {
				cout << ".";
			}
			else {
				cout << " ";
			}
		}
		cout << endl; 
	}
	cout << " 12345" << endl; 
	system("PAUSE");
	return 0;
}