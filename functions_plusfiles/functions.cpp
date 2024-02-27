#include <iostream>
#include <math.h>
#include "Func.cpp"
using namespace mt;

// Функция, она принимает на вход аргументы, и выдает значение в ответ
int/*<-тип возвращаемых данных*/ sumOfDigits/*<-название функции*/(int x)/*<-параметры (аргументы) функции*/
{
    int max = 0;
    while (x > 0)
    {
        if (max < x % 10)
            max = x % 10;
        x /= 10;
    }
    return max;//возврат ответа
}


// Процедура, принимает параметры, но значения не возвращает
void print10(std::string name)
{
    for (int i = 0; i < 10; i++)
    {
        std::cout << name << std::endl;
    }
}

// Правила
// 1. название функции
// 2. функция выполняет одно действие
// 3. Массивы всегда передаются по ссылке
// 4. Если хотим изменить переменную, передаем ее по ссылке(<-интересно что же это)

//Строго говоря указатели представляют собой объекты, значением которых служат адреса других объектов
//А по русски, указатель указывает на адрес в памяти, где распологается наша переменная и меняет ее (обозн. *)

//С помощью & можно получить адрес некоторого объекта, например, адрес переменной
// Передача параметров в функцию: по значению и по ссылке
void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void swapSort(int* mas, int n)  // Указатель
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (mas[i] > mas[j])
                swap(mas[i], mas[j]);
}

void printMenu(int& n)
{
    std::cout << "This is menu" << std::endl;
    std::cout << "1. Press K to write something" << std::endl;
    std::cin >> n;
}
bool isPrime(int x)
{
    if (x < 2)
        return false;
    for (int d = 2; d <= sqrt(x); d++)
    {
        if (x % d == 0)
            return false;
    }
    return true;
}

int main()
{
    std::string names = "lol";
    int n;
    printMenu(n);
    std::cout << n;
    int mas[10] = { 6,2,3,4,6 };
    swapSort(mas, 5);
    for (int i = 0; i < 5; i++)
        std::cout << mas[i] << " ";
    int x = 123;
    std::cout << sumOfDigits(x) << std::endl;
    std::cout << x << std::endl;

    int a = 5, b = 10;
    swap(a, b);
    std::cout << a << " " << b << std::endl;

    print10(names);

    int q;
    std::cin >> q;

    if (isPrime(q))
        std::cout << "Prime" << std::endl;
    else
        std::cout << "Not prime" << std::endl;

}

