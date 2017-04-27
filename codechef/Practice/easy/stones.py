import sys
t = int(input())

for i in range(t):
	c = 0
	j = set(input())
	s = input()
	for i in s:
		if(i in j):
			c+=1

	print(c)

sys.exit(0)

