t = list(map(int,input().split()))[0]
for _ in range(t):
   k,n = list(map(int,input().split()))
   c = 0
   x = k**n
   for i in range(1,k+1):
      c += (i**n)%(x)
   print(c)
