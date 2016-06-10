t = int(input())
for i in range(0,t):
	sum = 0
	a,b = input().split()
	for i in range(int(a),int(b)+1):
		if(str(i)==str(i)[::-1]):
			sum = sum + int(i)
	print(sum)