import math
t = list(map(int,input().split()))[0]
l = []
for i in range(97,123):
	l.append(chr(i))
for i in range(10):
	l.append(str(i))
s = set(l)
for _ in range(t):
	x = list(map(str,input().split()))[0]
	tes = []
	for i in x:
		tes.append(i)
	tes = set(tes)
	# print(s-tes)
	ss = len(s-tes)
	print(ss)
	fact = 1;
	for i in range(1,37):
		fact = (fact*i) % (1000000007)
		print(fact)
	print(fact%1000000007)
	print(math.factorial(ss)%(1000000007))