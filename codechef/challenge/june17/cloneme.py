t = int(input())
for i in range(t):
	n,q = map(int,input().split())
	l = list(map(int,input().split()))
	for i in range(q):
		a,b,c,d = map(int,input().split())
		x = list(l[a-1:b])
		y = list(l[c-1:d])
		x.sort()
		y.sort()
		cnt = 0
		for i,j in zip(x,y):
			if(i!=j):
				cnt+=1
				if(cnt>1):
					break
		if(cnt>1):
			print('NO')
		else:
			print('YES')