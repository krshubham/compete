from operator import mul
from functools import reduce
def solve(l,n,k):
	f = []
	op = 2**n
	for c in range(1,op):
		a = []
		for j in range(n):
			if(c & (1<<j)):
				a.append(l[j]);
		f.append(a)
	return(f)	


n,k = list(map(int,input().split()));
l = list(map(int,input().split()));
c = 0
f = solve(l,n,k)
print(f)
for i in f:
	if(reduce(mul,i,1) <= k):
		c+=1
print(c)