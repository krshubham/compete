t = int(input());
for i in range(t):
	l = set([i for i in input().split(' ')]);
	m = set([i for i in input().split(' ')]);
	if(len(l.intersection(m)) >= len(l)/2):
		print("similar");
	else:
		print("dissimilar");