a = int(input())
b = input()

sum = 0
for i in range(len(b)):
	x = int(b[i])
	sum+=x
	if(sum > a):
		print(0)
		break
else:
	
