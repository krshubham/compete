t = int(input())

for i in range(t):
	try:
		s = raw_input().split()
		a = int(s[1][0:2])*60 + int(s[1][3:5])
		b = int(s[2][0:2])*60 + int(s[2][3:5])
		print(a-b);
	except ValueError:
		continue

