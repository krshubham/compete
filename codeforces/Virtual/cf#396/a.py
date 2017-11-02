a = input()
b = input()
x = list(set(a).intersection(set(b)))
c = len(a)-len(x)
d = len(b) - len(x)
if(c == d):
	print('-1')
else:
	print(max(c,d)+1)