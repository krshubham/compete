from operator import mul
from functools import reduce
def solve(l,n,k):
	f = []
	op = 2**n
	for c in range(1,op):
		a = []
		for j in range(n):
			if(c & (1<<j)):
				a.append(l[j]) 
		f.append(a)
	return(f)

n,k = list(map(int,input().split()));
l = list(map(int,input().split()));
c = 0
f = solve(l,n,k)
for i in f:
	x = len(i)
	if((x > 2)):
		if(l[x-1] > k):
			continue
	if(i[0] > k):
		continue
	if(reduce(mul,i,1) <= k):
		c+=1
print(c)