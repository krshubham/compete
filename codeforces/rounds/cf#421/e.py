from functools import reduce
from operator import mul
import math

def length(n,m):
	return(n*n + m*m)

t = int(input())


for i in range(3*t):
	ni = list(map(int,input().split()))
	mi = list(map(int,input().split()))
	si = list(map(int,input().split()))
	n = reduce(mul,ni)
	m = reduce(mul,mi)
	s = reduce(mul,si)
	l = length(n,m)
	h = 2*s/b
	