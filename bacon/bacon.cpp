#include <iostream>
#include<string>
#include <limits>
#include <cstringt.h>
#include <algorithm> 
#include <functional>
#include <cctype>
using namespace std;

string key[26] = { "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z" };
string value[26] = { "aaaaa","aaaab","aaaba","aaabb","aabaa","aabab","aabba",
"aabbb","abaaa","abaab","ababa","ababb","abbaa","abbab","abbba","abbbb","baaaa","baaab","baaba","baabb","babaa",
"babab","babba","babbb","bbaaa","bbaab" };

string encrypt( string pt) {
	int i, j;
	string encrypt = "";
	for (i =0 ; i < pt.length(); i++) {
		for (j =0 ; j < 26; j++) {
			if (pt.substr(i, i + 1) == key[j]) {
				encrypt += value[j];
			}
		}
	}
	return encrypt;
}
string decrypt(string encp) {

	int i, j;
	string decrypt = "";
	for (i = 0; i < encp.length(); i+=5) {
		for (j = 0; j < 26; j++) {
			if (value[j]== encp.substr(i, i + 5)){

				decrypt += key[j];
			}
		}
	}
	return decrypt;
}
int main() {
	string pt, var;
	int x;
	while (true) {

		cout << "1. Zaszyfruj" << endl;
		cout << "2. Rozszyfruj" << endl;
		cin >> x;
		switch (x) {
		case 1:
			cout << "Podaj tekst: ";
			cin >> pt;
			transform(pt.begin(), pt.end(), pt.begin(), ::toupper);
			var = encrypt(pt);
			cout << var << endl;
			
			break;
		case 2:
			cout << "Podaj tekst do deszyfracji: ";
			cin >> pt;
			var = decrypt(pt);
			cout << var;
			break;
		}
	}
}
