#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;


//С использованием файловых и строковых потоков написать программу, которая считывает из текстового файла три предложения и выводит их в обратном порядке.


int main() {
	string path;
	cout << "Enter path to file: ";
	getline(cin, path);

	fstream f;

	f.open(path.c_str(), ios::in);

	if (!f) {
		cout << "Error: can't open file!" << endl;
		return 0;
	}

	stringstream ss1;

	char c = ' ';

	while (!f.eof() && (c != '.' && c != '!' && c != '?' && c != '\n')) {
		f.get(c);

		ss1 << c;
	}

	f.get(c);

	string s;
	cout << "Reverse: ";

	cout << s << " ";
	
	return 0;
}