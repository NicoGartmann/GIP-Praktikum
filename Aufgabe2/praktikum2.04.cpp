#include <iostream>
using namespace std; 

int main(){
double e = 0., d = 0.; //e= euro, d= dollar
cout << "Bitte geben Sie die Geldmenge in Euro ein: ?";
cin >> e;
d = e * 1.2957;
cout << "Die Geldmenge in US Dollar lautet: " << d << endl;
system("PAUSE");
}
