from math import sqrt
t = list(map(int,input().split()))[0]
for _ in range(t):
	x = list(map(int,input().split()))[0]
	n = ((x//7)/2)*(7+x)
	print(int(n))