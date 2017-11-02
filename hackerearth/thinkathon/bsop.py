import math

def f(x):
	return math.factorial(x)

def fact(a,i):
	if(i <= a):
		x = f(a)//(f(a-i)*f(i))
	else:
		x = a*i
	return x%1000000007

t = int(input())
for i in range(t):
	l = list(map(int,input().split()))
	a = l[0]
	b = l[1]
	c = l[2]
	d = l[3]
	x = 1;
	y = 1;
	for j in range(c,d+1):
		x*=fact(a,j)
	for j in range(c,d+1):
		y*=fact(b,j)
	print(x+y)