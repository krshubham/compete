t = int(input())
for i in range(t):
	n = input()
	ans = -1
	sx = 'null'
	# if(int(n[len(n)-1])%2 != 0):
	# 	print(-1)
	# 	continue
	for k in n:
		if(int(k)%2 == 0):
			break
	else:
		print(-1)
		continue
	for j in range(len(n)):
		an = ''
		for k in range(len(n)):
			if(k != j):
				an+=n[k]
		sa = an
		an = int(an)
		if(an%6 == 0):
			if(an > ans):
				sx = sa
				ans = an
	if(ans > -1):
		print(sx)
	else:
		print(-1) 