#include <iostream>
#include <ctime>
#include <string>
#include <bitset>
#include <random>
#include <sstream>
#include<limits>


using namespace std;

string encrypt(string sentence) {

	string szyfr, var;
	for (char word : sentence) {
		bitset<8> bit1(word);
		srand(time(NULL));
		bitset<8> bit2('a' + rand() % 26);
		var.append(bit2.to_string());
		bit1 = bit1 ^ bit2;
		szyfr.append(bit1.to_string());
	}
	return szyfr;
}
string decrypt(string code, string sentence) {
	int var = 2;
	string decrypt_senctence;
	for (int i = 0; i < code.length(); i += 8) {
		bitset<8> bit1(sentence.substr(i, 8));
		bitset<8> bit2(code.substr(i, 8));
		bitset<8> bit3 = bit1 ^ bit2;
		stringstream sstream(bit3.to_string());

		while (sstream.good()){
			bitset<8> bit4;
			sstream >> bit4;
			if (var % 2 == 0) {
				decrypt_senctence += char(bit4.to_ulong());
				var += 1;
			}
			else {
				var += 1;
			}
		}
	}
	return decrypt_senctence;
}
int main() {
	string sentence, code;
	int var;
	while (true) {
		cout << "Podaj zdanie / szyfr ";
		cin.ignore(numeric_limits < streamsize >::max(),'\n');
		getline(cin, sentence);
		cout << "1. Zaszyfruj" << endl;
		cout << "2. Odszyfruj" << endl;
		cin >> var;
		switch (var) {
		case 1:
			cout << encrypt(sentence);
			cout << endl;
			break;
		case 2:
			cin.ignore(numeric_limits < streamsize >::max(), '\n');
			cout << "Podaj kod: ";
			getline(cin, code);
			cout << decrypt(code, sentence);
			cout << endl;
			break;
		}
		
	}
	return 0;
}
