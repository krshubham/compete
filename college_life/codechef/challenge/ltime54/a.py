import operator
from functools import reduce
t = int(input())

def prod(iterable):
    return reduce(operator.mul, iterable, 1)

for i in range(t):
	a = list(map(int,input().split()));
	b = list(map(int,input().split()));
	c = list(map(int,input().split()));
	x = prod(b)
	for j in c:
		print(j//x,end=' ')
	print()
