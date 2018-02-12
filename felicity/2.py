x = 8
y = 8
for i in range(100000000):
	x += y
	y = x
print(x%1000000007)