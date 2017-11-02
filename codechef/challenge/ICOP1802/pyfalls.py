t = int(input())
for i in range(t):
	a,b,c = map(int,input().split())
	n = a*(a+1)//2
	n -= (b-1)
	print(n)