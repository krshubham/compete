t = int(input())
for i in range(t):
	a = int(input())
	count = 0
	while(a > 0):
		b = max([int(i) for i in str(a)])
		a -= b
		count+=1
	print(count)

