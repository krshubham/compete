t = int(input())
for _ in range(t):
	n = list(map(int,input().split()))[0]
	l = list(map(int,input().split()))
	s = ""
	for i in l:
		s += str(i)
	c = 0
	for i in s:
		c += int(i)
	if(c%3 == 0):
		print("Yes")
	else:
		print("No")
