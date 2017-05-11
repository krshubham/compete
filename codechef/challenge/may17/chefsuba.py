from collections import deque
import sys

def solve(l,n,k):
	r = 0
	for i in range(k):
		r += l[i]
	cs = r
	for i in range(k,n):
		cs += l[i] - l[i-k]
		r = max(r,cs)
	return(r)

n,k,p = list(map(int,input().split()))
l = deque(list(map(int,input().split())))
s = input()
for i in s:
	if i == '!':
		l.rotate(1)
	elif i == '?':
		a = solve(l,n,k)
		print(a)
sys.exit(0)