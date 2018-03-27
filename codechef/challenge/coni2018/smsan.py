# -*- coding: utf-8 -*-
# @Author: krshubham
# @Date:   2018-03-17 18:26:03
# @Last Modified by:   Kumar Shubham
# @Last Modified time: 2018-03-17 18:32:26
from fractions import Fraction
s = list(map(str,input().split()))
c = Fraction(0)
# print(s)
l = []
for i in s:
	l.append(i.lower())
print(l)
c += l.count("life")
c += l.count("love")
c += l.count("babe")
c += l.count("sweety")
print(Fraction(c)/Fraction(len(s)))