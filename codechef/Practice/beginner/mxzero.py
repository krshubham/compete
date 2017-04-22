t = int(input())

for i in range(t):
	n = int(input())
	s = [i for i in input().split(' ')]
	o = s.count('1')
	z = n - o
	print()
