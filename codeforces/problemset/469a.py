t = int(input())
a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]
a.pop(0)
b.pop(0)
a = set(a)
b = set(b)
c = a.union(b)
if(len(c) == t):
	print("I become the guy.")
else:
	print("Oh, my keyboard!")
