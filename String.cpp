#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

int main() {
    //стринг это массив char, тоесть как слово состоящее из букв, string состоит из char
	string str1 = "Hello";
	string str2 = "World";

	// Конкатенация строки (сложение)
    string result = str1 + " " + str2;
	cout << "Concatenated string: " << result << endl;

	// Длина строки(возвращает int)
	cout << "Length of the string: " << result.length() << endl;

	// Вывод одного символа (как элемент массива)
	cout << "First character: " << result[0] << endl;
	cout << "Last character: " << result[result.length() - 1] << std::endl;

	// Подстрока (кусок строки от 3 до 5 символа)
	std::string substring = result.substr(3, 5);
	std::cout << "Substring from index 3 to 7: " << substring << std::endl;

	// Вывод строки если он соответствует куску
	size_t found = result.find("World");
	if (found != std::string::npos) {
		std::cout << "Substring found at index: " << found << std::endl;
	}
	else {
		std::cout << "Substring not found" << std::endl;
	}

	// Замена куска строки
	result.replace(6, 5, "Universe");
	std::cout << "After replacement: " << result << std::endl;

	// Вывод строки в C-style (ещё один способ вывода)
	const char* cstr = result.c_str();
	std::cout << "C-style string: " << cstr << std::endl;

    //in>>str - считывает до первого пробела
    //getline(str) - считывает всё что написано с пробелами

    // Файловый ввод-вывод
	/*char str[100];  // '\n'
	ifstream in("input.txt", std::ios::in); // имя файла и спецификатор (для чтения) in - считывание, out - запись
	std::ofstream out("output.txt", std::ios::out);
	while (!in.eof())
	{
		in.getline(str, 100); 
		out << str << '\n';
	}*/
	return 0;
}
	
	
//Небольшая лаба на понимание
//Поиск в строке Hello World символ q, и счетаем их количество
/*
int main() {
	string s = "Helloqqww world";
	int c = 0;
	for (int i = 0; i < s.length(); i++) //используем for чтобы пройтись по всем элементам string 
	{
		if (s[i] == 'q') { //если i- тый элемент равен q (i=1,2,3,4...)
			c++; //то счетчик +1
		}
	}
	cout<< c; //
    return 0;
}*/
/*
//сравниваем две строки, проверяем есть ли элементы строки q в строке s
int main() {
	string s = "Hello world";
	string q = "qwrtpsdfghjklzxc";
	for (int i = 0; i < s.length(); i++) //первый for чтобы пройтись по всем элементам строки s
	{
		for (int j = 0; i < q.length(); i++){ //второй for чтобы пройтись по всем элементам q
		if (s[i] == q[j]) { //если попался одиннаковый
			cout << s[i];//выведем его
			}
		}
	}
return 0; //два for работают как поиск пары носков из двух куч, берете один левый носок, сравниваете со всеми правыми, потом берете второй левый и тд
}*/
//небольшая лаба на собственное понимае, есть 3 строки, сложить две первый и проверить если там элементы из 3 строки
// +поинты если сделаете ввод строк из файла :)
