# Тип данных bool
flag = True
flag1 = False  # 1 байт, True (1), False (0), True и False используются как поднятый и опущенный флаг
# флаг опущен, условия не выполняются, True выполняются

# Логические операторы
# not - НЕ
# or - ИЛИ (выполняется хотя бы одно условие)
# and - И (выполняются оба условия одновременно)

print(not flag)
print(flag or flag1)
print(flag and flag1)

# Операторы сравнения
# < меньше, > больше , <= меньше или равно, >= больше или равно, == равно , != не равно
cnt = 10
print(cnt > 5)
res = cnt > 5

# Условия
# if, if..else
# if используется для выполнения кода при выполнении условия
if cnt == 10:  # если переменная cnt равна 10
    print("CNT == 10")  # то выполняем этот код

if cnt > 10:
    print("First block")
else:
    print("Second block")




if cnt < 2 or cnt > 10:  # or - если хотя бы одно из условий выполняется
    print("Forth Block")
elif cnt == 4:  # elif - иначе если, аналог else с проверкой нового условия
    print("Third Block")

# Пример
if cnt == 1:
    print("One")
elif cnt == 2:  # если cnt не равен 1, проверяем равен ли он 2
    print("Two")
elif cnt == 3:
    print("Three")

# Switch в Python заменяется на if-elif-else, но для примера:
match cnt:  # начиная с Python 3.10
    case 0:
        print("Zero")
    case 1:
        print("One")
    case 2 | 3:
        print("Two or Three")
    case _:
        print("default")

# Цикл
i = 0  # Итератор, он же счетчик
while i < 10:  # Условие выполнения цикла
    print(i)
    i += 1  # Увеличение счетчика

j = 10
while j > 0:
    print(j)
    j -= 1  # Уменьшение счетчика

# Область видимости переменной: глобальная и локальная
x = 10  # глобальная переменная
print(x)

if cnt > 2:
    y = 100  # локальная переменная, создается при выполнении условия
    print(y)

while i < 10:
    y = 0  # переменная y пересоздается при каждом шаге цикла
    print(i + y)
    i += 1

# счетчик, условие, шаг
for j in range(10):  # это как int j=0; while (j<10) { j++ }
    print(j)

# команда break выводит нас из цикла while или for
# Поиск числа в последовательности, с которого сумма s > 1000
s = 0
for i in range(1, 10000):
    s += i
    if s > 1000:  # если нашли такое число
        break  # выходим из цикла

# Упражнения

# Ввести натуральные числа A, B и C. 
# Если A кратно B и B больше C, то вывести A/B + C, 
# если A кратно B и B меньше C, то вывести A/B - C, 
# в остальных случаях вывести (A + B) * C.
A = int(input("Введите A: "))
B = int(input("Введите B: "))
C = int(input("Введите C: "))

if A % B == 0 and B > C:
    print(A // B + C)
elif A % B == 0 and B < C:
    print(A // B - C)
else:
    print((A + B) * C)

# Ввести натуральные числа A, B и C. 
# Если A + B кратно C и C кратно B, то вывести (A + B) / C - C / B, 
# если A + B кратно C и C не кратно B, то вывести (A + B) / C + B * C, 
# в остальных случаях вывести A - B + C.
A = int(input("Введите A: "))
B = int(input("Введите B: "))
C = int(input("Введите C: "))

if (A + B) % C == 0 and C % B == 0:
    print((A + B) // C - C // B)
elif (A + B) % C == 0 and C % B != 0:
    print((A + B) // C + B * C)
else:
    print(A - B + C)
