#include<iostream>
#include<cstdlib>
#include<string>
#include<limits>
using namespace std;

void ROT13(string a)
{
    for (int i = 0; i <= a.length(); i++){      //pętla przechodząca przez wszystkie litery w zdaniu
        if (a[i] < 91 && a[i] > 64){            //duże litery
            if (a[i] < 78)
                a[i] = a[i] + 13;
            else
                a[i] = a[i] - 13;
        }
        if (a[i] < 123 && a[i] > 96){           //małe litery 
            if (a[i] < 110)
                a[i] = a[i] + 13;
            else
                a[i] = a[i] - 13;
        }
    }
    cout << a << endl;
}
int main() {
	bool status = true;	
	string expression;
    cout << "Aby zakonczyc program wcisnij enter" << endl;
	do {
		cout << "Wpisz zdanie do zaszyfrowania lub deszyfrowania." << endl;
		getline(cin, expression);
		ROT13(expression);
		if (expression.empty()){
			status = false;
		}
	}while (status == true);
	return 0;
}