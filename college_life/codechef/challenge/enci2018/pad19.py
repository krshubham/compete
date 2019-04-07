t = list(map(int,input().split()))[0]
for _ in range(t):
	n = list(map(int,input().split()))[0]
	l = list(map(float,input().split()))
	x = list(map(float,input().split()))[0]
	print(sum(l)*x)