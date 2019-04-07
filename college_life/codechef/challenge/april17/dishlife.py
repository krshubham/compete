import sys
t = int(input());

for i in range(t):
	a,b = [int(i) for i in input().split(' ')];
	m = [];
	count = 0;
	for i in range(a):
		c = input();
		l = c.split(' ');
		l.remove(l[0]);
		m.append(set(l));
	for i in m:
		count += 1;
		if(len(m[0].union(i)) == b and count < a):
			print('some');
			break;
		elif(len(m[0].union(i)) == b):
			print('all');
			break;
	else:
		print('sad');
sys.exit(0);