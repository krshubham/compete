t = int(input())
dp = {}
def ans(a,l,r):
	x = -99999999999999999999999;
	for i in range(l-1,r):
		x = max(x,(a[i]-a[l-1])*(a[r-1]-a[i]))
	return x

for i in range(t):
	n,q = map(int,input().split())
	l = list(map(int,input().split()))
	for i in range(q):
		a,b,c = map(int,input().split())
		if(a == 1):
			print(ans(l,b,c))
		else:
			l[b-1] = c