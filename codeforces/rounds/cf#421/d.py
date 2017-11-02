import sys

def rotate(l, n):
    return l[n:] + l[:n]


n = int(input())
a = list(map(int,input().split()))
x = ' '.join(a)

rotate(a,1)
print(x)
ms = 999999
t = 0
while True:
	n = []
	for b,c in enumerate(a):
		n.append(abs((b+1)-c))
	ns = sum(n)
	ms = min(ms,ns)
	if(ms == 0):
		print(0,end=' ')
		print(t)
		sys.exit(0)
	t+=1
	rotate(a,1)
	print(a)
	print(x)
	if(a == x):
		print(ms,end=' ')
		print(t)
		sys.exit(0)
