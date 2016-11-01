def my_decorator(pstr):
    def decor(fn):
        def wrapper():
            return print(fn().count(pstr))
        return wrapper
    return decor


@my_decorator('123')
def my_func():
    return '12,123,123,123,32111,123,sad'

my_func()
