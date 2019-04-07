def base_convert(i, b):
    result = []
    while i > 0:
            result.insert(0, i % b)
            i = i // b
    return result


t = int(input())
for i in range(t):
	n = int(input())
	a = input()
	b = int(a,4)
	l = []
	dict = {}
	for i in range(n):
		r = b%(2**i)
		if(r != b):
			dict[r]
		else:
			break
		l.sort();
		for i in l:
			print(i,end='')
