n = int(input().split()[0])
for _ in range(n):
	a,b = map(int,input().split())
	l = [i.strip() for i in input().split(' ')]
	c = 0
	for j in range(a-1):
		if(len(set(l[j]).intersection(set(l[j+1]))) == 0):
			c+=1
		if(c > b):
			print('Very poor choice of words')
			break
	else:
		print('Welcome to a world without rules')
