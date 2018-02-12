n = list(map(int,input().split()))[0]
x=0
if n%2==0:
	x=(n//2) * (n//2+1)
else:
	x= (n//2 +1)**2
print(x)
