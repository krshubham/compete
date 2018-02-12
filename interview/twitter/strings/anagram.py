import sys
t = int(input())
for _ in range(t):
	s = input()
	x = input()
	if(len(s) != len(x)):
		print("NO")
		continue
	for i in s:
		if(x.count(i) != s.count(i)):
			print("NO")
			break
	else:
		print("YES")