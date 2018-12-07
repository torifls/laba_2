#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(){
	setlocale(LC_ALL, "");
	const int files_cnt = 3;//количество файлв
	string files[files_cnt];
	//считываем имена файлов
	for(int i = 0; i < files_cnt; ++i){
		cout << "Введите путь к файлу " << i + 1 << ": ";
		cin >> files[i];
	}
	for(int i = 0; i < files_cnt; ++i){
		ifstream in(files[i]);
		string line;//предложение
		stringstream ss;//строковый поток
		int counter = 0;//счётчик предложений
		while(getline(in, line)){//считываем по предложению
			 ++counter;
			 string tmp = ss.str();
			 ss.str(string());
			 ss << line << '\n' << tmp;
		}
		cout << '\n' << files[i] << '\n';
		if(counter == 3){
			cout << ss.str();
		}
		else if(counter < 3){
			cout << "Предложений меньше 3";
		}
		else{
			cout << "Предложений больше 3";
		}
		in.close();//закрываем файл			
	}
	system("pause>>void");

}