t = int(input());
for i in range(t):
	houses = [i for i in range(1,101)];
	m,x,y = [int(i) for i in input().split(' ')];
	reach = x*y;
	g = [int(i) for i in input().split(' ')];
	done = False;
	for i in g:	
		if(i - reach <= 0 and i+ reach >= 100):
			for j in range(1,101):
				try:
					houses.remove(j);
				except ValueError:
					continue;
		elif(i-reach <= 0 and i+reach < 100):
			for j in range(1,i+reach+1):
				try:
					houses.remove(j);
				except ValueError:
					continue;
		elif(i-reach > 0 and i+reach >= 100 ):
			for j in range(i-reach, i + reach + 1):
				try:
					houses.remove(j);
				except ValueError:
					continue;
		elif(i - reach > 0 and i + reach < 100):
			for j in range(i-reach, i+reach+1):
				try:
					houses.remove(j);
				except ValueError:
					continue;
		if(len(houses) == 0):
			done = True;
			print(0);
			break;
	if(not(done)):
		print(len(houses));