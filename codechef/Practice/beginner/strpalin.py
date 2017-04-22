t = int(input())

for i in range(t):
	a = set(input())
	b = set(input())
	j = a.intersection(b);
	if(len(j) >= 1):
		print('Yes')
	else:
		print('No')
