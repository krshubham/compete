t = int(input())
while(t!=0):
	l = [i for i in input().split()]	
	k = int(l[2])
	ans = 0
	count = 0
	for i in range(int(l[0]),int(l[1])+1):
		i = str(i)
		for j in i:
			if(int(j) != 0  and int(i)%int(j)==0):
				ans+=1
			else:
				continue
		if(ans>=k):
			count+=1
	print(count)	
	t = t-1