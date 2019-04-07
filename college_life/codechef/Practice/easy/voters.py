a,b,c = [int(i) for i in input().split(' ')];
x=[],y=[],z=[]
for i in range(a):
	x.append(int(input()))
x = set(x)
for i in range(b):
	y.append(int(input()))
y = set(y)
for i in range(c):
	z.append(int(input()))
z = set(z)
