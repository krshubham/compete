t=int(input())

for k in range(t):
	a=input()
	c=0
	e=0
	s=0
	flag=1
	for i in a:
		if i == 'C':
			if s==0:	
				c=c+1;
			else:
				flag=0
				break
		elif i == 'E':
			if s==0:
				if c>0:
					e=e+1
					c=c-1
				else:
					flag=0
					break
		elif i == 'S':
			s=s+1;
	if flag==0:
		print('no')
	elif flag==1:
		print('yes')
			

	