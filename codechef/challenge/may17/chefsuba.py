from collections import deque
import sys
from itertools import islice
def window(seq, n=2):
    it = iter(seq)
    result = tuple(islice(it, n))
    if len(result) == n:
        yield result    
    for elem in it:
        result = result[1:] + (elem,)
        yield result


def solve(l,n,k):
	a = ["".join(x) for x in window("".join(str(y) for y in l), k)]
	print(a);
	for i in a:
		m = i.count('1')
		print(m)
		if(m >= k):
			ans = k
			return ans 
		else:
			ans = m
	return ans

n,k,p = list(map(int,raw_input().split()))
l = deque(list(map(int,raw_input().split())))
s = raw_input()
for i in s:
	if i == '!':
		l.rotate(1)
	elif i == '?':
		a = solve(l,n,k)
		print(a)
sys.exit(0)