def calculate (N):
	numbers_parititioned = {}
	c = N[0];
	numbers_parititioned[c] = 1
	for i in range(1,len(N)):
		c += N[i]
		numbers_parititioned[c] = 1
	try:
		length = len(N)
		for i in range(len(N)-1,-1,-1):
			print(N[:i])
	except KeyError:
		pass

N = input()

out_ = calculate(N)
print (out_)