n,m,y = map(int,input().split())
c = 0
for i in range(m):
	if(((i**n)%m) == y):
		print(i,end=' ')
		c+=1
if(c == 0):
	print(-1)
