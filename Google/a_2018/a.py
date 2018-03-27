# -*- coding: utf-8 -*-
# @Author: krshubham
# @Date:   2018-03-18 10:35:22
# @Last Modified by:   Kumar Shubham
# @Last Modified time: 2018-03-18 21:41:40
import string
import itertools
digs = string.digits + string.ascii_letters


def int2base(x, base):
    if x < 0:
        sign = -1
    elif x == 0:
        return digs[0]
    else:
        sign = 1

    x *= sign
    digits = []

    while x:
        digits.append(digs[int(x % base)])
        x = int(x / base)

    if sign < 0:
        digits.append('-')

    digits.reverse()

    return ''.join(digits)
# l = []
# i = 1
t = list(map(int,input().split()))[0]
for _ in range(t):
	n = list(map(int,input().split()))[0]
	# fl = 0
	# for j in str(n):
	# 	if(j == '0' or j == '2' or j == '4' or j == '6' or j == '8'):
	# 		continue
	# 	else:
	# 		fl = -1
	# 		break
	# if(fl == 0):
	# 	print("Case #{}: 0".format(_+1))
	# 	continue
	# if(fl == 0):
	# 	c = min(c,n-ans)
	# low = 1
	# high = int(1e11)
	# while(2*int(int2base(low,5)) < n):
	# 	low*=2
	# while(2*int(int2base(high,5)) > n):
	# 	high //=2
	# low //=2
	# high *= 2
	# a = 0
	# b = 0
	# for i in itertools.count():
	# 	if(2*int(int2base(low,5)) < n):
	# 		low += 10
	# 	else:
	# 		a = 1
	# 	if(2*int(int2base(high,5)) > n):
	# 		high -= 10
	# 	else:
	# 		b = 1
	# 	if(a == 1 and b == 1):
	# 		break
	# # print(low,high)
	# # print(low)
	# # print(high)
	# # print(2*int(int2base(low//2,5)))
	# # print(2*int(int2base(high*2,5)))
	# c = 99999999999999999999
	# ans = 2*int(int2base(low,5))
	# # print(ans)
	# for i in range(ans,n-1,-1):
	# 	fl = 0
	# 	for j in str(i):
	# 		if(j == '0' or j == '2' or j == '4' or j == '6' or j == '8'):
	# 			continue
	# 		else:
	# 			fl = -1
	# 			break
	# 	if(fl == 0):
	# 		# print(i)
	# 		c = min(c,abs(i-n))
	# d = 99999999999999999999
	# ans = 2*int(int2base(high,5))
	# # print(ans)
	# for i in range(ans,n+1):
	# 	fl = 0
	# 	for j in str(i):
	# 		if(j == '0' or j == '2' or j == '4' or j == '6' or j == '8'):
	# 			continue
	# 		else:
	# 			fl = -1
	# 			break
	# 	if(fl == 0):
	# 		# print(i)
	# 		d = min(d,abs(i-n))
	# # print(c,d)
	# # print(min(c,d))
	s = str(n)
	c = -1
	for i in range(len(s)):
		if(int(i)%2 == 1):
			c = i
			break
	ans = 0
	if(c == -1):
		pass
	else:
		s1 = ""
		s2 = ""
		for i in range(c):
			s1 += s[i]
			s2 += s[i]
		s1 += s[c]-1	
	print("Case #{}: {}".format(_+1,min(c,d)))


