t = int(input())
for i in range(t):
	x = int(input())
	c = 2<<(x-1)
	s = 0
	k = str(c)
	for j in k:
		s+=int(j)
	print(s)
