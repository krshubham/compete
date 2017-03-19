t = int(input());
for i in range(t):
	n,m,k = [int(i) for i in input().split(' ')];
	l = set([i for i in range(1,n+1)]);
	s1 = set([int(i) for i in input().split(' ')]);
	s2 = set([int(i) for i in input().split(' ')]);
	a1 = s1.intersection(s2);
	print(len(a1),end=' ');
	print(len(l.difference(s2).difference(s1)));

