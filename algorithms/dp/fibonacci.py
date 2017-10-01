a,b,n = input().split()
a = int(a)
b = int(b)
n = int(n)

dp = [-1]*30

def fib(n):
	if(n <= 1):
		return(a)
	elif(n==2):
		return(b)
	try:
		if(dp[n] == -1):
			dp[n] = fib(n-1)**2 + fib(n-2)
			return(dp[n])
		else:
			return(dp[n])
	except KeyError:
		pass

print(fib(n))
