n = map(int,input().split())
x = n
while(len(str(x)) != 1):
	c = 1
	for i in str(x):
		if(int(i) != 0):
			c*=int(i)
	x = c

print(x)