import sys
a = list(input().split(' '))
t = int(input())
x = t%4
if(x == 1):
	if(ord(a[0]) == 94 and ord(a[1]) == 62):
		print('cw')
		sys.exit(0)
	elif(ord(a[0]) == 62 and ord(a[1]) == 118):
		print('cw')
		sys.exit(0)
	elif(ord(a[0]) == 118 and ord(a[1]) == 60):
		print('cw')
		sys.exit(0)
	elif(ord(a[0]) == 60 and ord(a[1]) == 94):
		print('cw')
	else:
		print('ccw')
elif(x == 3):
	if(ord(a[0]) == 94 and ord(a[1]) == 60):
		print('cw')
		sys.exit(0)
	elif(ord(a[0]) == 62 and ord(a[1]) == 94):
		print('cw')
		sys.exit(0)
	elif(ord(a[0]) == 118 and ord(a[1]) == 62):
		print('cw')
		sys.exit(0)
	elif(ord(a[0]) == 60 and ord(a[1]) == 118):
		print('cw')
		sys.exit(0)
	else:
		print('ccw')
		sys.exit(0)
else:
	print('undefined')