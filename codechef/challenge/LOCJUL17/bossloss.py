import math
t = int(input())

for i in range(t):
	n,m = map(int,input().split(' '))
	x = (-1 + math.sqrt(8*m+1))/2
	if(math.ceil(x) > n):
		print(-1)
	else:
		print(math.ceil(x))
