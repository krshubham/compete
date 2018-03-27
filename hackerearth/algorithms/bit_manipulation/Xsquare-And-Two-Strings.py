t = int(input())
for i in range(t):
	a = input()
	b = input()
	a = set(a)
	b = set(b)

	if(len(a.intersection(b)) > 0):
		print("Yes")
	else:
		print("No")