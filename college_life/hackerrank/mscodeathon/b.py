import sys
import math

l = []
def sorter(a):
	if(a == 'lexicographic'):
		l.sort(key=lambda x:x[test[0]-1])
	else:
		l.sort(key=lambda x:int(x[test[0]-1]))

n = int(input())
for _ in range(n):
	l.append(list(map(str,input().split())))
test = list(map(str,input().split()))
test[0] = int(test[0])
sorter(test[2])
if(test[1] == 'true'):
	l = l[::-1]
for i in l:
	for j in i:
		print(j,end=' ')
	print("")
	