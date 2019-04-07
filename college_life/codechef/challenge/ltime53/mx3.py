t = int(input())
for i in range(t):
	n = input()
	c = len(n)
	if(int(n[c-1])%2 != 0 and int(n[c-2])%2 != 0):
		print(-1)
		continue
	ans = '-1'
	for k in n:
		if(int(k)%2 == 0):
			break
	else:
		print(-1)
		continue
	for j in range(c):
		an = n[:j] + n[j+1:]
		if(int(an)%6 == 0):
			if(an > ans):
				ans = an
	if(ans > '-1'):
		print(ans)
	else:
		print(-1) 