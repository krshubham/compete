import sys
n = int(input())
l=[]
for i in range(0,n):
	l.append(int(input()))
l.sort()
for i in l:
	print(i)
sys.exit(0)