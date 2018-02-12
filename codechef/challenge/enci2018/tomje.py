import math
t = list(map(int,input().split()))[0]
for _ in range(t):
	n = list(map(int,input().split()))[0]
	print(math.floor(n*math.log10(math.factorial(n))) + 1)