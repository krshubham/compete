t = map(int,input().split())
for _ in range(t):
	a,b=map(int,input().split())
	c,d=map(int,input().split())
	r=set(range(b, 10000, a))
	m=set(range(d, 10000, c))
	ans=r&m
	if ans:
	    print(min(ans))
	else:
	    print(-1)