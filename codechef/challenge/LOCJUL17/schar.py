t = int(input())
for i in range(t):
	a = input()
	print(abs(ord(a[len(a)-1]) - ord(a[0])))
