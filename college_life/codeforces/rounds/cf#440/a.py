a,b = map(int,input().split())
l = list(map(int,input().split()))
x = list(map(int,input().split()))

numlist = []
if(len(set(l).intersection(x)) == 0):
	for i in l:
		for j in x:
			numlist.append(int(str(i) + str(j)))
	for i in x:
		for j in l:
			numlist.append(int(str(i) + str(j)))
	# print(numlist)
	print(min(numlist))
else:
	print(min(list(set(l).intersection(x))))