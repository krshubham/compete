def log_message(func):
    def wrapper(*args, **kwargs):
        result = func(*args, **kwargs)
        path = '/tmp/decorator_logs.txt'
        openedFile = open(path, 'a+')
        openedFile.write(result)
        openedFile.close()
        return result
    return wrapper

@log_message
def cool():
  return "Hello Prashant"

@log_message
def a_function_newline(s):
  return "{}\n".format(s)

cool()
a_function_newline('Prashant')
