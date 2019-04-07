t = int(input());
for i in range(t):
	n = int(input());
	l = [int(j) for j in input().split(' ')];
	l.sort();
	for i in range(0, len(l)-1):
		if(not(l[i + 1] - l[i] == 1)):
			print(l[i + 1]) if (i != 0) else print(l[i]);
			break;

