t = int(input())
for i in range(t):
	n = int(input())
	l = set([int(i) for i in raw_input().split(' ')]);
	m = [int(i) for i in raw_input().split(' ') if int(i) >= 15]
	if(len(l) != 1):
		print('No Party')
	else:
		if(len(m) == n):
			print('Party')
		else:
			print('No Party')