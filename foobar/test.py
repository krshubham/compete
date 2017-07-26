def answer(arr):
	if(len(arr) == 1):
		return arr[0]
	product = 1

	MIN = 99999999

	neg = 0
	pos = 0

	cz = 0

	for i in arr:
		if(i<0):
			neg+=1
			MIN = min(MIN, abs(i))
		elif i>0:
			pos+=1

		if(i == 0):
			cz = True
		else:
			product = product*i

	if(neg & 1):
		product = product/-MIN

	if(neg == 1 and pos == 0 and cz==True):
		product = 0
	return product

