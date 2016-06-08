n = int(input())
for i in range(0,n):
	a,b = input().split()
	a = int(a)
	b = int(b)
	l=[]
	for j in range(1,b+1):
		l.append(a%j)
	print(max(l))