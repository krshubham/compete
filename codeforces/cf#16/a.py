a,b = map(int,input().split(' '))
z = False
y = []
for i in range(a):
	x = set(input())
	if(z == True):
		continue
	if(len(x) != 1):
		z = True	
	else:
		z = False
		for k in x:
			break
		y.append(k)
if(z == True):
	print('NO')
else:
	for i in range(len(y)-1):
		if(y[i] == y[i+1]):
			print('NO')
			break
	else:
		print('YES')