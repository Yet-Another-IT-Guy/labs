def my_decorator(fn, str1):
    def wrapper():
        str_c = fn()
        return print(str_c.count(str1))
    return print(wrapper)
@my_decorator('aaab')
def my_func():
    return 'aaabbbb2342342df'
  
my_func()
