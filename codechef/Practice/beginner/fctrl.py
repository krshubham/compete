# import math
# n = int(input())
# for i in range(0,n):
# 	count=0
# 	a = int(input())
# 	for i in str(math.factorial(a))[::-1]:
# 		if(i=='0'):
# 			count+=1
# 		else:
# 			break
# 	print(count)

#large factorial implementation in python

import math

def multiply(n,res,res_size):
	carry = 0
	for i in range(0,res_size):
		prod = res[i]*x*carry
		res[i] = prod%10
		carry = prod//10
	while(carry):
		res[res_size] = carry%10
		carry = carry//10
		res_size+=1
	return(res_size)

def factorial(n):
	l=[]
	l[0] = 1
	res_size = 1
	for i in range(2,n+1):
		res_size = multiply(i,l,res_size)
	print("Factorial of the given number is: ")
	for i in range(res_size-1,-1,-1):
		print(l[i])
factorial(100)
