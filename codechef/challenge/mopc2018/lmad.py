import numpy as np
t = list(map(int,input().split()))[0]
for _ in range(t):
	n = list(map(int,input().split()))[0]
	m = list(map(int,input().split()))[0]
	lt = []
	for i in range(n):
		temp = list(map(str,input().split()))
		lt.append(temp)
	l = []
	for i in lt:
		temp = []
		for j in i:
			j = j.replace('->','')
			j = j.replace('\\n','')
			temp.append(int(j))
		l.append(temp)
	x = list(map(int,input().split()))[0]
	y = list(map(int,input().split()))[0]
	if(m != x):
		print('The Matrix Multiplication is not possible')
		continue
	lt = []
	for i in range(n):
		temp = list(map(str,input().split()))
		lt.append(temp)
	l2 = []
	for i in lt:
		temp = []
		for j in i:
			j = j.replace('->','')
			j = j.replace('\\n','')
			temp.append(int(j))
		l2.append(temp)
	# print(l*l2)
	
	l = np.matrix(l)
	l2 = np.matrix(l2)
	ans = (l*l2).tolist()
	print(n)
	print(y)
	for i in ans:
		for j in range(len(i)):
			if(j == len(i)-1):
				print(str(i[j])+'->\\n',end=' ')
			else:
				print(str(i[j])+'->',end=' ')
		print()
	