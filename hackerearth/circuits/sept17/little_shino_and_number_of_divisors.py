n = input()
a = map(int,raw_input().split())

larr = [1]
c = 1

for i in range(n-1):
	c *= (a[i]+1)
	c %= 1000000007
	larr.append(c)
b = a[::-1]
rarr = [1]
c = 1
for i in range(n-1):
	c *= (b[i]+1)
	c %= 1000000007
	rarr.append(c)
rarr = rarr[::-1]
l = []
for j in range(n):
	i = a[j]
	l.append((((i*(i+1))/2)*rarr[j]*larr[j])%1000000007)
ans = 1
for i in l:
	ans *= i+1
	ans %= 1000000007
print ans