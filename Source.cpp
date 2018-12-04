#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

/*
С использованием файловых и строковых потоков написать программу, которая считывает из текстового файла три предложения и выводит их в обратном порядке.
*/

int main() {
	string path;
	cout << "Enter path to file: ";
	getline(cin, path);

	fstream f;
	f.exceptions(ifstream::failbit);
	try {
		f.open(path.c_str(), ios::in);
		stringstream ss1;
		stringstream ss2;
		stringstream ss3;
		char c = ' ';

		while (!f.eof() && (c != '.' && c != '!' && c != '?' && c != '\n')) {
			f.get(c);

			ss1 << c;
		}

		f.get(c);

		while (!f.eof() && (c != '.' && c != '!' && c != '?' && c != '\n')) {
			ss2 << c;
			f.get(c);
		}

		ss2 << c;
		f.get(c);

		while (!f.eof() && (c != '.' && c != '!' && c != '?' && c != '\n')) {
			ss3 << c;
			f.get(c);
		}

		ss3 << c;
		f.close();

		string s;
		cout << "Reverse: ";

		getline(ss3, s);
		cout << s << " ";
		getline(ss2, s);
		cout << s << " ";
		getline(ss1, s);
		cout << s << " ";
		//system("pause");
	}
	catch (const ifstream::failure& exc)
	{
			cout << "Error: can't open file!" << endl<<exc.what()<<endl;
	}
	return 0;
}