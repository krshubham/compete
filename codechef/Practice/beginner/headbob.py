n = int(input())
for i in range(0,n):
	r = int(input())
	a = input()
	if('I' in a):
		print("INDIAN")
	elif('I' not in a and 'Y' not in a):
		print("NOT SURE")
	else:
		print("NOT INDIAN")