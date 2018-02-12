import math
from fractions import gcd
def isPrime(a):
    return all(a % i for i in range(2, math.ceil(math.sqrt(a))))

l = [0]*1005
for n in range(4,1001):
	c = 0;
	if(not isPrime(n)):
		for a in range(1,1000):
			#a is coprime to n and satisfies the condition
			if(gcd(n,a) == 1 and (a**n)%n == (a%n)):
				c+=1
	l[n] = c
# print(max(l))
print(l.index(max(l)))