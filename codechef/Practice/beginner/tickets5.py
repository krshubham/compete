a = int(input());
for i in range(a):
	b = input();
	s = set([i for i in b]);
	if(len(s)!=2):
		print('NO')
	else:
		print('YES')