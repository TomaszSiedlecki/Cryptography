#include <iostream>
#include <string>
#include<algorithm>

using namespace std;
string change(string text, string key) {
	string w = "";
	for (int i = 0; i < text.length(); i++) {
		int przes = (key[i % key.length()] - 'A');
		int point = (text[i] - 'A');
		w += ((char)('A' + (-point + 26 + przes) % 26));
	}
	return w;
}


int main() {

	int state;
	string key, tekst;
	cout << "1. Szyfrowanie \n2. Deszyfrowanie \n";
	cin >> state;
	if (state == 1) {
		cout << "Podaj klucz:\n";
		cin >> key;
		cin.ignore();
		cout << "Podaj tekst:\n";
		getline(cin, tekst);

		transform(key.begin(), key.end(), key.begin(), ::toupper);
		transform(tekst.begin(), tekst.end(), tekst.begin(), ::toupper);

		string szyfr = change(tekst, key);
		cout << "Tekst zaszyfrowany" << szyfr;
		
	}
	else if (state == 2){
		cout << "Podaj klucz:\n";
		cin >> key;
		cin.ignore();
		cout << "Podaj tekst:\n";
		getline(cin, tekst);

		transform(key.begin(), key.end(), key.begin(), ::toupper);
		transform(tekst.begin(), tekst.end(), tekst.begin(), ::toupper);

		string szyfr = change(tekst, klucz);
		cout << "Tekst odszyfrowany" << szyfr;
	}
	else {
		cout << "Brak opcji" << endl;
	}
	return 0;
}