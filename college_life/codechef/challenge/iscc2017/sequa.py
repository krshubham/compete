t = int(input())

def solve(n,p,m):
	if p==0:
		return(1)
	nm = n%m
	r = solve(nm,p//2,m)
	r = (r*r)%m
	if(p%2 == 0):
		return(r)
	return((r * nm)%m)


for i in range(t):
	n,m = map(int,input().split(' '))
	sum = 0
	for i in range(n+1):
		sum += (solve(i,i,m))%m
	print(sum)
