t = int(input())
while(t!=0):
	a = input()
	print("wins")if(a==a[::-1])else(print("losses"))
	t = t-1