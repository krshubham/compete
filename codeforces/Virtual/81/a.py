l = list(map(float,input().split()))
l[0] = int(l[0])
l[1] = int(l[1])
l[2] = float(l[2])
print(l)
d = {}
for _ in range(l[0]):
	a,b = list(map(str,input().split()))
	b = int(b)
	if(l[2]*b >= 100):
		d[a] = int(l[2]*b)
ans = set()
for _ in range(l[1]):
	ans.add(())
