import re
a = [m.start() for m in re.finditer('(?=ama)', 'amamamama')]
print(a)
