from itertools import permutations
perms = [''.join(p) for p in permutations('chef')]
t = list(map(int,input().split()))[0]
for _ in range(t):
	s = input()
	c = 0 
	for i in perms:
		if(i in s):
			c+=s.count(i)
	if(c > 0):
		print("lovely "+str(c))
	else:
		print('normal')