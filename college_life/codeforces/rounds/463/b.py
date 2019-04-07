n = list(map(int,input().split()))[0]

def f(x)
	c = 1
	for i in str(x):
		if(i != '0'):
			c *= int(i)
	return(c)

def g(x):
	if(x < 10):
		return x
	else:
		return g(f(x))

for _ in range(n):
	l,r,k = list(map(int,input().split()))[0]
	for i in range (l,r+1):
		if(g(i))
