n = int(input())
for i in range(0,n):
	a = int(input())
	count=0
	if(a<=2048):
		a = str(bin(a))
		for j in a:
			if(j=='1'):
				count+=1
	else:
		if(a%2048 != 0 ):
			b = str(bin(a%2048))
			for i in b:
				if(i=='1'):
					count+=1
			count = a//2048 + count
		else:
			count = a//2048
	print(count) 
