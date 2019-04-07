import math
t = list(map(int,input().split()))[0]
for _ in range(t):
	n = list(map(int,input().split()))[0]
	c = n*(n+1)*(2*n+1)//6
	n+=1
	x = (n**2)*((n**2)-1)//12
	print(math.floor(x/c))