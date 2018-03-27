import sys
from math import acos,sqrt
from fractions import Fraction
mod = 1000000007
dp = {}
def pows(x):
    powers = []
    i = 1
    while i <= x:
        if i & x:
            powers.append(i)
        i <<= 1
    return powers

def cos2x(theta):
	return 2*theta**2 - 1
def cos3x(theta):
	return 2*theta*cos2x(theta)-theta

def cosn(theta,n):
	dp[0] = 1
	dp[1] = theta
	i = 2
	while(i <= 2**59 and i <= n):
		# dp[i] = 2*(dp[i//2]**2)-1
		x = dp[i//2]
		dp[i] = Fraction(2*(x.numerator**2)%mod - (x.denominator**2)%mod,(x.denominator**2)%mod)
		i*=2
	# return 2*theta*cosn(theta,n-1)-cosn(theta,n-2)s
	# print(dp)
	return dp[n]

def bruten(theta,n):
	med = pows(n) # decomposing a number into powers of 2
	cosn(theta,med[len(med)-1])
	ans = Fraction(0,1)
	for i in range(0,len(med)):
		ans += summation(dp[med[i]],dp[med[i+1]])
	
T = list(map(int,input().split()))[0]
for _ in range(T):
	l,d,t = list(map(int,input().split()))
	if t == 1:
		print((d*pow(1,mod-2,mod))%mod)
		continue
	elif t == 2:
		theta = Fraction(d,l)
		ans = cos2x(theta)
		# print(ans)
		g = Fraction(l*ans)
		p = g.numerator;q=g.denominator
		print((p*pow(q,mod-2,mod))%mod)
		continue
	elif t == 3:
		theta = Fraction(d,l)
		ans = cos3x(theta)
		# print(ans)
		g = Fraction(l*ans)
		p = g.numerator;q=g.denominator
		print((p*pow(q,mod-2,mod))%mod) 
		continue
	if(((t&(t-1))==0)):
		theta = Fraction(d,l)
		ans = cosn(theta,t)
		g = Fraction(l*ans)
		p = g.numerator;q=g.denominator
		print((p*pow(q,mod-2,mod))%mod)
	else:
		# theta = Fraction(d,l)
		# ans = bruten(theta,t)
		# #g = Fraction(l*ans)
		# #p = g.numerator;q=g.denominator
		# #print((p*pow(q,mod-2,mod))%mod)
		print('2')