В жизни бывает так, что какую-то операцию необходимо исполнить несколько раз, мало меняя логику действий.


```python
# прочитаем число, прочитаем второе и сложим
a = int(input())
b = int(input())
summ = a + b
print("Сумма: ", summ)
```

    Сумма:  2
    


```python
# а теперь сделаем так 4 раза
a = int(input())
b = int(input())
c = int(input())
d = int(input())
summ = a + b + c + d
print("Сумма: ", summ)
```

    Сумма:  4
    

Нетрудно заметить, что никакой новой логики в программу не добавилось. Если задуматься, то кажется, что по-сути одинаковые программы являются совершенно несовместимыми и разными. 
Если нам добавить ещё число, то опять писать новую программу. Нужен способ лучше!


```python
# Представляем цикл for
# В цикле мы можем описать повторяющиеся действия и исполнить их несколько раз 

summ = 0 # заранее создадим сумму, без значения, даже нулевого, никак!  

for i in range(5): # i - переменная цикла. range() - генератор диапазона. Сейчас от 0 до 4 (итого 5 значений)
    print(i, end=' ') # Печатаем значение i - номер прохода цикла
    summ += int(input())
print("Сумма:", summ) 

```

    0 1 2 3 4 Сумма: 7
    

Прогресс налицо! Программа стала короче, так ещё и для увеличения количества слагаемых нам достаточно поменять одну цифру. 
Зачем останавливаться на достигнутом? Давайте предложим пользователю ввести количество слагаемых.


```python
cycles = int(input("Ввведите кол-во слагаемых: ")) # input() может печатать приглашательное сообщение

summ = 0
for i in range(cycles):
    summ += int(input())
print("Сумма:", summ) 
```

    Сумма: 4
    


```python
# Разберёмся с range() - генератором диапазона
# range принимает до 3-x аргументов, обязателен к указанию один

# range(конец_диапазона) генерирует последовательность от 0 до конца, НЕ ВКЛЮЧАЯ КОНЕЦ
# ожидаем 0 1 2 3
for i in range(4):
    print(i, end=' ')

print('')
# range(начало, конец) даёт нам последовательность ВКЛЮЧАЯ НАЧАЛО но НЕ ВКЛЮЧАЯ КОНЕЦ с шагом 1
for i in range(5, 14):
    print(i, end=' ')

# если начало > конец, то пустой диапазон
for i in range(3, -4):
    print(i, end=' ')

print('')
# range(начало, конец, шаг) - диапазон от [начала до конца), но мы идём с шагом
for i in range(2, 16, 2):
    print(i, end=' ')

print('')
# Можно шагать назад
for i in range(3, -4, -1):
    print(i, end=' ')

```

    0 1 2 3 
    5 6 7 8 9 10 11 12 13 
    2 4 6 8 10 12 14 
    3 2 1 0 -1 -2 -3 


```python
# Задача: Посчитаем среднее арифметическое 
# Среднее = сумма_всех / кол-во чисел

steps = int(input("Ввведите число итераций: "))
summ = 0
for i in range(steps):
    summ += int(input())
median = summ / steps
print("Среднее:", median) 
```

    Среднее: 3.0
    


```python
# Задача: Посчитаем произведение всех чётных до 20, включая 20!

# Вариант 1 - с шагом
result = 1
for i in range(2, 21, 2): # начнём с 2-х, конец 21, последним будет 20, шагаем по 2
    result *= i
print(result)

# Вариант 2 - с условием
result = 1
for i in range(2, 21):
    if i % 2 == 0: # делится без остатка на 2?
        result *= i
print(result)
```

    3715891200
    3715891200
    


```python

```