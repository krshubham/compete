t = list(map(int,input().split()))[0]
for _ in range(t):
	a,b = list(map(int,input().split()))
	x = a**6
	c = 0
	for i in str(x):
		c += int(i)
		c%=9
	y = b%6
	d = 0
	for i in str(a**y):
		d += int(i)
		d %= 9
	print(c)