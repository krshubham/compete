import sys
n = int(input())
for i in range(0,n):
	l = [int(i) for i in input().split()]
	l.sort()
	print(l[1])
sys.exit(0)
