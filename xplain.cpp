#include <iostream>
#include <random>
#include <cmath>

// Функция для проверки, является ли число простым
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// Функция для генерации случайного простого числа
int generatePrime() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(2, 100); // Измените диапазон, если требуется большее простое число
    int num = dist(gen);
    while (!isPrime(num)) {
        num = dist(gen);
    }
    return num;
}

// Функция для вычисления наибольшего общего делителя (НОД)
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Функция для вычисления функции Эйлера
int eulerFunction(int p, int q) {
    return (p - 1) * (q - 1);
}

// Функция для генерации ключей
void generateKeys(int& k, int& d, int& s) {
    int p = generatePrime();
    int q = generatePrime();
    
    // Вычисление s
    s = p * q;
    
    // Вычисление функции Эйлера
    int F = eulerFunction(p, q);
    
    // Генерация числа k, меньшего F и взаимно простого с F
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(2, F - 1);
    k = dist(gen);
    
    while (gcd(k, F) != 1) {
        k = dist(gen);
    }
    
    // Поиск числа d такого, что (d * k) mod F = 1
    for (int i = 1; i < F; ++i) {
        if ((i * k) % F == 1) {
            d = i;
            break;
        }
    }
}

// Функция для шифрования данных с использованием открытого ключа
int encrypt(int M, int k, int s) {
    int result = 1;
    
    while (k > 0) {
        if (k & 1) {
            result = (result * M) % s;
        }
        M = (M * M) % s;
        k >>= 1;
    }
    
    return result;
}

// Функция для дешифровки данных с использованием закрытого ключа
int decrypt(int B, int d, int s) {
    int result = 1;
    
    while (d > 0) {
        if (d & 1) {
            result = (result * B) % s;
        }
        B = (B * B) % s;
        d >>= 1;
    }
    
    return result;
}

int main() {
    int k, d, s; // Переменные для хранения ключей
    generateKeys(k, d, s); // Генерация ключей
    
    int M = 10; // Число для шифрования
    int encryptedData = encrypt(M, k, s); // Шифрование данных
    std::cout << "Зашифрованные данные: " << encryptedData << std::endl;
    
    // Отправка зашифрованных данных на станцию
    
    int decryptedData = decrypt(encryptedData, d, s); // Дешифровка данных
    std::cout << "Расшифрованные данные: " << decryptedData << std::endl;
    
    return 0;
}
