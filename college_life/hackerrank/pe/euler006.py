t = int(input())

for i in range(t):
	x = int(input())
	s = x*(x+1)*(2*x+1)/6
	print(int((((x)*(x+1))/2)**2 - s))