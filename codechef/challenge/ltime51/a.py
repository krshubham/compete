import math
t = int(input())

for i in range(t):
	a,b = input().split(' ')
	a = int(a)
	b = int(b)
	x = math.pow(2,a)
	y = x
	c = a
	yo = b
	for j in range(0,a):
		if(yo%2==0):
			xy= math.pow(2,c)
			xx=yo%xy
			yo = yo - (xx//2)
		else:
			xy= math.pow(2,c)
			xx=yo%xy
			xx= math.pow(2,c)-xx-1
			yo=yo+(xx)//2
		c-=1
	print(yo)