class Poly:
	def __init__(self,a,b,c,d):
		self.a = a
		self.b = b
		self.c = c
		self.d = d
	def solve(self,x):
		return ((self.a) + (self.b)*(x) + (self.c)*(x*x) + (self.d)*(x*x*x))

t = int(input())
for _ in range(t):
	n = int(input())
	l = []
	cnt = 0
	minm = 9999999
	maxm = -9999999
	mina = 999999
	for i in range(n):
		a,b,c,d = map(int,input().split())
		if(c == 0 and d == 0):
			minm = min(minm,b)
			maxm = max(maxm,b)
			mina = min(mina,a)
			cnt+=1
		p = Poly(a,b,c,d)
		l.append(p)
	if(cnt == n):
		#All equations are straight lines
		q = int(input())
		for __ in range(q):
			x = int(input())
			f(x == 0):
				print(mina)
			else:
				print(minm*x + mina)
	else:
		q = int(input())
		for i in range(q):
			x = int(input())
			c = 99999999999999999999
			for j in l:
				c = min(c,j.solve(x))
			print(c)



