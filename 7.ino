// Функция для проверки, является ли число простым(простое значит делится только на 1 и себя)
bool isPrime(int num) {//вносим в функцию переменную num
    if (num <= 1) {
        return false;//1 и 0 простыми по определению не являются
    }
    for (int i = 2; i <= sqrt(num); i++) { //от двух до корня из num, раз проверяем сколько делителей имеет число
        if (num % i == 0) {//если находим делитель не равный 1 или самому себе
            return false;//то число не простое
        }
    }
    return true;//иначе оно простое
}


// Функция для генерации случайного простого числа
int generatePrime() {
    int num = random(2, 200);//num = рандомное число от 2 жо 200
    while (!isPrime(num)) { //если это рандомное число простое
        num = random(2, 200);//то заново генерируем число
    }
    return num;//и возвращаем его
}

// Функция для вычисления наибольшего общего делителя (НОД)
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);//рекурсивно делим одно число на другое пока не получим НОД
}


// Функция для генерации ключей
void generateKeys(int& k, int& d, int& s) {

    randomSeed(analogRead(A0)); //генерируем рандомное число
    int p = generatePrime(); //сгенерируем простое число p и q
    int q = generatePrime();
    
    // Вычисление s
    s = p * q;

    // Вычисление функции Эйлера
    int F = (p - 1) * (q - 1);

    k = random(2, F); //создаем рандомное число от 2 до F

    while (gcd(k, F) != 1) {//постоянно создает рандомное число k пока НОД с F не равен 1
        k = random(2, F);
    }
    
    // Поиск числа d такого, что (d * k) mod F = 1
    for (int i = 1; i < F; i++) {
        if ((i * k) % F == 1) {
            d = i;
            break;
        }
    }
}
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
// Функция для шифрования данных с использованием открытого ключа
long encrypt(long M, long k, long s) {
    long result = 1;

    while (k > 0) {
        if (k & 1) {
            result = (result * M) % s; //обновляем результат
        }
        M = (M * M) % s; //обновляем М
        k >>= 1; //двигаемся в право (для следующего бита)
    }

    return result;
}

// Функция для дешифровки данных с использованием закрытого ключа
long decrypt(long B, long d, long s) {
    long result = 1;

    while (d > 0) {//проходимся по битам d
        if (d & 1) {
            result = (result * B) % s; //обновляем result
        }
        B = (B * B) % s;//обновляем b для следующей итерации
        d >>= 1;//двигаемся в право по битам
    }

    return result;
}

void setup() {

    Serial.begin(9600);

    int k, d, s; // Переменные для хранения ключей
    generateKeys(k, d, s); // Генерация ключей

    //Serial.println(k);
    //Serial.println(d);
    //Serial.println(s);

    int M = 10; // Число для шифрования
    long encryptedData = encrypt(M, k, s); // Шифрование данных
   

    // Отправка зашифрованных данных на станцию
    Serial.println(encryptedData);

    long decryptedData = decrypt(encryptedData, d, s); // Дешифровка данных
    Serial.println(decryptedData);
    
}

void loop(){

}