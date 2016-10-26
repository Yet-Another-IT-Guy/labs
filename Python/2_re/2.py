import re


# Функция проверки слова на палиндром
def isPalindrom(wrd):
    if not wrd:
        return False
    wrd = wrd.lower()
    if wrd == wrd[::-1]:
        return True
    else:
        return False

f = open('input', 'r')
text = f.read()
result = text.split('.')
print(result)
print(isPalindrom('abbaa'))
