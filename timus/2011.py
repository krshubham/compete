from math import factorial
n = int(input())
l = list(map(int,input().split()))
x = factorial(l.count(1))*factorial(l.count(2))*factorial(l.count(3))
if(factorial(6) // x) >= 6:
	print("Yes")
else:
	print('No')