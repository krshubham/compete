t = int(input());
for i in range(t):
	a,b = [int(i) for i in input().split()];
	old = [i for i in input().split(' ')];
	l = [];
	for i in range(b):
		inp = input();
		z = inp.split(' ');
		z.pop(0);
		for j in z:
			l.append(j)
	l = set(l);
	for i in old:
		if(i in l):
			print("YES",end=' ');
		else:
			print("NO",end=' ');