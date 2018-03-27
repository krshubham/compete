from math import sqrt
t = list(map(int,input().split()))[0]
for _ in range(t):
	a,b,c = list(map(int,input().split()))
	x,y,z = list(map(int,input().split()))
	d = sqrt((x-a)**2 + (y-b)**2)
	if( c > d+z):
		print("C1CC2")
	elif(z > d+c):
		print("C2CC1")
	elif(z == d+c or c == d+z):
		print("C2~C1")
	else:
		print("NOT SATISFIED")