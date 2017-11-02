a,b,c = map(int,input().split())
l = []
x = []
for i in range(1,c+1):
	if(a*i > c and b*i > c):
		break
	l.append(a*i)
	x.append(b*i)

l = set(l)
x = set(x)
print(len(l.intersection(x)))
