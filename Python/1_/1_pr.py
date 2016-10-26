curr = input('Введите построчно последовательность чисел. Конец последовательности "."\n')
suitable = []
while curr == '.' or curr == '':
    print('Пустая последовательность\n')
    curr = input('Введите построчно последовательность чисел. Конец последовательности "."\n')
while True:
    if curr == '.':
        break
    try:
        if int(curr) % 3 == 0:
            suitable.append(curr)
    except:
        print("Ошибка. Введите число!")
    curr = input()
print('Числа, кратные 3\n')
print(suitable)
