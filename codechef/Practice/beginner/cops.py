t = int(input());
for i in range(t):
	houses = [i for i in range(1,101)];
	m,x,y = [int(i) for i in input().split(' ')];
	reach = x*y;
	cops = [() for i in input().split(' ')]