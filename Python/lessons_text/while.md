# Цикл while

Цикл с предусловием - выполняется, ПОКА условие верно, проверяя условие в начале каждого цикла.


```python
# Простой цикл с счётчиком
i = 0
while i < 10: # пока i меньше 10, проверяет между проходами
    i += 1 
    print(i, end=' ') # напечатает 10, а после цикл закончится
```

    1 2 3 4 5 6 7 8 9 10 


```python
i = 7
# Логические значения, они же boolean, они же булевый тип
i_gtt_5 = i > 5 # Да, сравнение это такая же операция, как сложение
print("i больше пяти?", i_gtt_5)

# принимают два значения True и False, истинна и ложь

t = True
f = False
print(t, f)
```

    i больше пяти? True
    True False
    

Наш цикл на самом деле работает, ПОКА ему передают ИСТИНУ (True)


```python
while False: # никогда не случится
    print('ложь!')

# Классический приём - цикл с флагом
flag = True # Заводим логическую переменную - наш "флаг"
i = 0
while flag:
    print(i, end=' ') # печатаем перед инкрементом, увидим и 0 и 13
    flag = i < 13 # обновляем флаг в цикле
    i += 1 # инкремент
```

    0 1 2 3 4 5 6 7 8 9 10 11 12 13 


```python
# Пример: принимать, пока дают

next_input = input()
while next_input != '': # '!=' - не равно, а '' - пустая строка
    print(next_input) # просто возвращаем напечатаное
    next_input = input()
```


```python
# Применение: Принимать числа, пока дают, а потом сложить

summ = 0
next_input = input()
while next_input != '':
    summ += int(next_input) # конвертируем в число на месте
    next_input = input() # и снова просим значение
print("Сумма:", summ)
```

    Сумма: 3
    

## Про логические операции


```python
# Математические
print(3 < 4) # Меньше
print(4 <= 4) # Меньше или равно
print(4 > 5) # Больше (ложь)
print(6 >= 2) # Больше или равно

# Резутьтаты можно присваивать
a = 4 == 4 # равно (как логическая операция требует 2-х равно, чтобы отличить от присваивания) 
b = a != False # не равно
print("Четыре это четыре?", a, "Прошлое не ложь?", b)
```

    True
    True
    False
    True
    Четыре это четыре? True Прошлое не ложь? True
    


```python
# Логические операции
print(5 > 4 and 5 < 8) # И (верны оба)
print(5 < 1 or 7 < 10) # ИЛИ (верно хотя бы одно)
print(not False) # НЕ

print('')
# исключающее или (верно ТОЛЬКО одно)
print(True ^ False) 
print(False ^ True)
print(True ^ True)
```

    True
    True
    True
    
    True
    True
    False
    


```python
# Оператор is
A = 4
B = 4
print(A is B) # Для примитив, как обычное равно

C = {"обьект": 'не примитив'}
D = {"обьект": 'не примитив'}
F = C
print("С это D?", C is D) # мы сравниваем происхождение, а не содержание (по умному это адрес)
print("C это F?", C is F) # а вот F = C, мы присвоили F само C
```

    True
    С это D? False
    C это F? True
    

## Примеры про циклы 


```python
# Алгоритм Евклида
# Ищем НОД двух чисел

a = int(input())
b = int(input())
 
while a != 0 and b != 0: # пока оба не нулевые 
    if a > b:
        a = a % b # сохраняем остаток от деления большего на меньшее
    else:
        b = b % a

# раз одно ноль, то сумма это и есть общий делитель, где бы он ни был
print(a + b)

```

    2
    

## Метод биекции

Любое уравнение можно записать как f(x) = 0 <br/>
А значит решить уравнение - это найти икс, при котором значение функции равно 0

Метод биекции прост: возьмём отрезок [a, b], если f(a) < 0 и f(b) > 0, то где-то между находится значение 0. <br/>
Мы не можем гарантировать, что мы приземлимся на ноль, но можно принять за точность ширину отрезка. <br/>
*Конечно мы должны понимать, на каком отрезке искать, но это меньшее из зол*


```python
# Пример: решим уравнение x**7 - 2*x**2 = 0 
# Понятное дело, что корень ноль, но есть ещё один - чуть больше единицы

f = lambda x: x**7 - 2*x**2 # не обращайте внимания, просто функция f(x)

a = 0.5 # очень грубо оценим корень снизу
b = 2 # ещё грубее сверху

if f(a) < f(b): # хотим считать, что на [a, b] f возрастает, так что перевернём отрезок если надо
    a, b = b, a # меняем местами

steps = 0
while abs(a - b) > 0.0001: # точность с которой ищем корень
    c = (a + b) / 2 # берём середину
    if f(c) > 0: # если в середине отрезка мы больше нуля
        a = c # сдвигаем верхнюю границу в середину
    else:
        b = c # сдвигаем нижнюю границу в середину, в ином случае
    
    steps += 1 # просто из интереса

print(a, 'за', steps, 'шагов')
```

    1.14874267578125 за 14 шагов
    

При всей простоте настолько надёжен, что иногда обходит более хитрые методы, даже если в среднем требует больше итераций <br/>
Бывает так, что другие методы просто не находят корня

> В `Kerbal Space Program` для решения уравнения Кеплера при построении гиперболических орбит используется метод биекции <br/>

Ещё одним преимуществом является то, что про саму функцию нам не нужно знать совершенно ничего
