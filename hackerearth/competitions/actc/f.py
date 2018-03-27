# -*- coding: utf-8 -*-
# @Author: krshubham
# @Date:   2018-03-23 01:25:28
# @Last Modified by:   Kumar Shubham
# @Last Modified time: 2018-03-23 09:01:31
def is_cube(n):
	cube_root = abs(n)**(1./3.)
	return(round(cube_root) ** 3 == abs(n))

def is_sqrt(n):
	if(n < 0):
		return False
	cube_root = n**(1./2.)
	return(round(cube_root) ** 2 == n)

# def build_zero_array(array):
# 	ret = [0]*len(array)
# 	if(array[0] == 0):
# 		ret[0] = 1
# 	for i in range(1, len(array)):
# 		ret[i] = ret[i - 1] + (0 if array[i] else 1)
# 	return ret


# def check_zeros(zero_array, array, i, j):
# 	return zero_array[j] - zero_array[i] + (0 if array[i] else 1)

# n,q = list(map(int,input().split()))
# l = list(map(int,input().split()))
# ans = []
# ans.append(l[0])
# for i in range(1,n):
# 	ans.append(ans[i-1]*l[i])
# # print(ans)
# zeros = build_zero_array(l)
# print(zeros)
# for _ in range(q):
# 	x,y = list(map(int,input().split()))
# 	if(check_zeros(zeros,l,x-1,y-1)):
# 		print('Both')
# 		continue
# 	test = ans[y-1]/ans[x-1] * l[x-1]
# 	# print(test)
# if(is_cube(test) and is_sqrt(test)):
# 	print('Both')
# elif(is_cube(test)):
# 	print('Cube')
# elif(is_sqrt(test)):
# 	print('Square')
# else:
# 	print('None')


def build_products_array(array):
	ret = [0 for i in range(len(array))]
	ret[0] = array[0]
	last_value = 1 if array[0]==0 else array[0]
	for i in range(1, len(array)):
		if array[i]:
			ret[i] = last_value * array[i]
			last_value = ret[i]
		else:
			ret[i] = last_value
	return ret


def build_zero_array(array):
	ret = [0 for i in range(len(array))]
	ret[0] = 1 if array[0]==0 else 0
	for i in range(1, len(array)):
		ret[i] = ret[i - 1] + (0 if array[i] else 1)
	return ret


def check_zeros(zero_array, array, i, j):
	return zero_array[j] - zero_array[i] + (0 if array[i] else 1)


def query(products, zero_array, array, start, end):
	if check_zeros(zero_array, array, start, end):
		return 0
	else:
		return products[end] // products[start] * array[start]


def main():
	n,q = list(map(int,input().split()))
	array = list(map(int,input().split()))
	products = build_products_array(array)
	zeros = build_zero_array(array)
	for _ in range(q):
		x,y = list(map(int,input().split()))
		test = query(products,zeros,array,x-1,y-1)
		if(is_cube(test) and is_sqrt(test)):
			print('Both')
		elif(is_cube(test)):
			print('Cube')
		elif(is_sqrt(test)):
			print('Square')
		else:
			print('None')

main()
