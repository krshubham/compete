t = int(input())
a = input()
count = 0
zc=0
st=''
i = 0
while (i<t):
	while(int(a[i]) == 1):
		count+=1
		if(i==t-1):
			break
	print(count)
	while(int(a[i]) == 0):
		zc+=1
		if(i==t-1):
			break
	print(zc)
	if(count != 0):
		st+=str(count)
		count = 0
	if(zc != 0):
		for j in range(zc-1):
			st+=str(0)
		zc = 0
print(st)

