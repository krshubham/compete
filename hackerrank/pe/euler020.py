import math
t = int(input())
for i in range(t):
	n = int(input())
	s = 0;
	for j in str(math.factorial(n)):
		s+=int(j)
	print(s)
