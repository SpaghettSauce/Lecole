#include <iostream>
#include <fstream>
#include <string>
//using namespace std;



void readfile_writefile (){
    char str[100];  
	std::ifstream in("input.txt", std::ios::in); // имя файла и спецификатор (для чтения) in - считывание, out - запись
	std::ofstream out("output.txt", std::ios::out);//out - запись
	while (!in.eof()) //пока в файле есть символы которые мы ещё не посмотрели
	{
		in.getline(str, 100); //считываем символы из нашего файла(in), и записываем их в массив str,считывание будет идти пока символы не закончаться или пока не попадется символ "\n"(конкатенирующий символ)
		out << str << '\n'; //записываем данный с массива str в другой файл, когда напишем всю строку символо, добавим в конце "\n"
	}
}

int main() {
    readfile_writefile();
    return 0;
}
