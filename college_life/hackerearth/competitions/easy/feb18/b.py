t = int(input())
for _ in range(t):
	ans = 0
	a,b = list(map(int,input().split()))
	for j in range(a,b+1):
		cnt = 0
		c = 0
		for x in str(j):
			if(x == '0'):
				continue
			cnt+=1
			c += int(x)**int(x)
		z = 0
		for x in str(j):
			if(x != '0'):
				if(c%int(x) == 0):
					z+=1
		if(z == cnt):
			print(j)
			ans+=1
	print(ans)

