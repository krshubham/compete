s = set(input())
t = int(input())

for i in range(t):
	if(len(s.union(set(input()))) == len(s)):
		print('Yes')
	else:
		print('No')