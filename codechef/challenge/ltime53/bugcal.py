t = int(input())
for i in range(t):
	a,b = map(int,input().split())
	x = max(a,b)
	y = min(a,b)
	nul = []
	ans = ''
	for j,k in zip(str(x)[::-1],str(y)[::-1]):
		z = str(int(j)+int(k))
		nul.append(z[len(z)-1])
	for xl in nul[::-1]:
		# print(xl,end='')
		ans+=xl
	c = len(str(x))
	d = len(str(y))
	if(c > d):
		for li in range(0,c-d):
			print(str(x)[li],end='')
			# ans+=str(x)[li]
	else:
		for li in range(0,d-c):
			print(str(y)[li],end='')
			# ans += str(y)[li]
	print(int(ans))

