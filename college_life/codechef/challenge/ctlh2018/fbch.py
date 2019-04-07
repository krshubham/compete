# Python 3 Program to find n'th fibonacci Number in
# with O(Log n) arithmatic operations
MAX = 1003
 
# Create an array for memoization
f = [0] * MAX
 
# Returns n'th fuibonacci number using table f[]
def fib(n) :
    # Base cases
    if (n == 0) :
        return 0
    if (n == 1 or n == 2) :
        f[n] = 1
        return (f[n])
    if (f[n]) :
        return f[n]
 
    if( n & 1) :
        k = (n + 1) // 2
    else : 
        k = n // 2
    if((n & 1) ) :
        f[n] = (fib(k) * fib(k) + fib(k-1) * fib(k-1))
    else :
        f[n] = (2*fib(k-1) + fib(k))*fib(k)
 
    return f[n]

t = list(map(int,input().split()))[0]
for _ in range(t):
	n = list(map(int,input().split()))[0]
	if(fib(n)%2 == 0 and fib(n)%5 == 0):
		print("yes")
	else:
		print("no")