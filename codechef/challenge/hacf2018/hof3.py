from math import sqrt
t = list(map(int,input().split()))[0]
for _ in range(t):
	a,b,c = list(map(int,input().split()))
	x,y,z = list(map(int,input().split()))
	d = sqrt((x-a)**2 + (y-b)**2)
	if(d == c+z):
		print("tangential")
	elif(d < c+z):
		print("overlapping")
	else:
		print("not overlapping")