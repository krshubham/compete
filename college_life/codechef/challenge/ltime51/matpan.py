t = int(input())

x = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
for j in range(t):
	a = [int(i) for i in input().split(' ')]
	b = set([i for i in input()]);
	sum = 0
	for i in (list(set(x)-b)):
		sum += a[ord(i)-97]
	print(sum)
