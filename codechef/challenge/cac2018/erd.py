t = list(map(int,input().split()))[0]
for _ in range(t):
	n = list(map(int,input().split()))[0]
	l = list(map(int,input().split()))
	m = list(map(int,input().split()))
	c = 0
	for i in range(n):
		c += (m[i]**3)*l[i]
	print(c)