t = int(input())
for i in range(t):
	s = input()
	l = len(s)
	if(l%2 == 0):
		s1 = s[:l//2]
		s2 = s[l//2:]
	else:
		s1 = s[:l//2]
		s2 = s[l//2 + 1:]
	a = list(s1)
	b = list(s2)
	a.sort()
	b.sort()
	for i in range(0,len(a)):
		if(a[i] != b[i]):
			print('NO')
			break;
	else:
		print('YES')


