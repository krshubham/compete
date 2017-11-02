n,m,x,k = map(int,input().split())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
l = []
for i in range(min(n-1, m - x-1)+1):
	for j in range(i+x,m):
		l.append(a[i]*b[j])

l.sort()
print(l[k-1])