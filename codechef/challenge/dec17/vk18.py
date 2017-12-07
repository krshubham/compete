t = int(input())
for _ in range(t):
	n = int(input())
	l = [[0 for x in range(n)] for y in range(n)]
	c = 0
	for i in range(n):
		for j in range(n):
			l[i][j] = i+j+2
			oc = 0
			ec = 0
			for k in str(l[i][j]):
				if(int(k)&1):
					oc+=int(k)
				else:
					ec+=int(k)
			c += abs(oc-ec)
	print("n = "+str(n)+" c = "+str(c))
	for i in l:
		for j in i:
			print(j,end=' ')
		print()	
	print('----------------------')