from itertools import permutations
def occurrences(string, sub):
    count = start = 0
    while True:
        start = string.find(sub, start) + 1
        if start > 0:
            count+=1
        else:
            return count

t = list(map(int,input().split()))[0]
for _ in range(t):
	a = list(map(str,input().split()))[0]
	b = list(map(str,input().split()))[0]
	perms = set([''.join(p) for p in permutations(a)])
	d = {}
	c = 0
	ans = ""
	for i in perms:
		d[i] = occurrences(b,i)
		c = max(c,d[i])
	if(c == 0):
		print(-1)
	else:
		l = []
		for i in d:
			if(d[i] == c):
				l.append(i)
		l.sort()
		try:
			print(l[0])
		except:
			print(-1)