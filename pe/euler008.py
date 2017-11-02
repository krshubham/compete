t = int(input())
for i in range(t):
	n,k = map(int,input().split())
	x = input()
	d = 0
	c = 1
	for i in range(k):
		c*=int(x[i])
	d = max(d,c)
	j = k-1
	i = 0
	while(j != n-1):
		j+=1
		if(x[i] != '0'):
			c//=int(x[i])
			c*=int(x[j])
			i+=1
			d = max(d,c)
	print(d)





